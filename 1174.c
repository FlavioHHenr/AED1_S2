#include <stdio.h>

#define SIZE 100

int main() {
    double A[SIZE];
    
    // Ler 100 valores
    for (int i = 0; i < SIZE; i++) {
        scanf("%lf", &A[i]);
    }

    // Exibir posições e valores menores ou iguais a 10
    for (int i = 0; i < SIZE; i++) {
        if (A[i] <= 10) {
            printf("A[%d] = %.1f\n", i, A[i]);
        }
    }

    return 0;
}
