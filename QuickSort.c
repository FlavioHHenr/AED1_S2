#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para trocar dois elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para particionar o array
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivô
    int i = (low - 1);     // Índice do menor elemento

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Função principal do QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Ordenar os elementos separadamente antes e depois do pivô
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Função para gerar um array de números aleatórios
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000; // Números aleatórios entre 0 e 99999
    }
}

// Função para medir o tempo de execução
double measureTime(void (*sortFunc)(int[], int, int), int arr[], int n) {
    int *temp = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }

    clock_t start = clock();
    sortFunc(temp, 0, n - 1);
    clock_t end = clock();

    free(temp);
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

// Função principal
int main() {
    // Tamanhos dos arrays para testar
    int sizes[] = {20000, 40000, 60000, 80000, 100000, 120000, 140000, 160000, 180000, 200000, 
                   220000, 240000, 260000, 280000, 300000, 320000, 340000, 360000, 380000, 400000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    printf("QuickSort Performance:\n");
    printf("Size\tTime (s)\n");
    printf("------------------------\n");

    // Salvar dados em arquivo CSV
    FILE *file = fopen("quicksort_data.csv", "w");
    fprintf(file, "Size,Time\n");

    // Para cada tamanho, executar e medir o tempo
    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        int *arr = malloc(n * sizeof(int));
        generateRandomArray(arr, n);

        double time_taken = measureTime(quickSort, arr, n);
        printf("%d\t%.6f\n", n, time_taken);
        fprintf(file, "%d,%.6f\n", n, time_taken);

        free(arr);
    }

    fclose(file);
    return 0;
}
