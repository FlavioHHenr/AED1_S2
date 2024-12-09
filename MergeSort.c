#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para mesclar duas subpartes do array
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Arrays temporários
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    // Copiar dados para os arrays temporários
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    // Mesclar os arrays temporários de volta ao array original
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar os elementos restantes de L[], se existirem
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar os elementos restantes de R[], se existirem
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

// Função principal do Merge Sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Ordenar as metades
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Mesclar as metades ordenadas
        merge(arr, l, m, r);
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

int main() {
    int sizes[] = {20000, 40000, 60000, 80000, 100000, 120000, 140000, 160000, 180000, 200000, 
                   220000, 240000, 260000, 280000, 300000, 320000, 340000, 360000, 380000, 400000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    printf("Merge Sort Performance:\n");
    printf("Size\tTime (s)\n");
    printf("------------------------\n");

    // Salvar dados em arquivo CSV
    FILE *file = fopen("merge_sort_data.csv", "w");
    fprintf(file, "Size,Time\n");
  
    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        int *arr = malloc(n * sizeof(int));
        generateRandomArray(arr, n);

        double time_taken = measureTime(mergeSort, arr, n);
        printf("%d\t%.6f\n", n, time_taken);
        fprintf(file, "%d,%.6f\n", n, time_taken);

        free(arr);
    }

    fclose(file);
    return 0;
}
