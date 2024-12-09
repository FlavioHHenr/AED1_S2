#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move os elementos maiores que a chave uma posição à frente
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Função para gerar um array de números aleatórios
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000; // Números aleatórios entre 0 e 99999
    }
}

// Função para medir o tempo de execução
double measureTime(void (*sortFunc)(int[], int), int arr[], int n) {
    int *temp = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }

    clock_t start = clock();
    sortFunc(temp, n);
    clock_t end = clock();

    free(temp);
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}


int main() {
    // Tamanhos dos arrays para testar
    int sizes[] = {0, 20000, 40000, 60000, 80000, 100000, 120000, 140000, 160000, 180000, 200000, 
                   220000, 240000, 260000, 280000, 300000, 320000, 340000, 360000, 380000, 400000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    printf("Insertion Sort Performance:\n");
    printf("Size\tTime (s)\n");
    printf("------------------------\n");

    // Salvar dados em arquivo CSV
    FILE *file = fopen("insertion_sort_data.csv", "w");
    fprintf(file, "Size,Time\n");

    // Para cada tamanho, executar e medir o tempo
    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        int *arr = malloc(n * sizeof(int));
        generateRandomArray(arr, n);

        double time_taken = measureTime(insertionSort, arr, n);
        printf("%d\t%.6f\n", n, time_taken);
        fprintf(file, "%d,%.6f\n", n, time_taken);

        free(arr);
    }

    fclose(file);
    return 0;
}
