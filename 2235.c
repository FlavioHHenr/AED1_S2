#include <stdio.h>

int main() {
    int A, B, C;
    
    // Ler os créditos
    while (scanf("%d %d %d", &A, &B, &C) != EOF) {
        // Checar todas as combinações possíveis
        int possible = 0;

        // Usando um crédito
        if (A == 0 || B == 0 || C == 0) possible = 1;

        // Usando dois créditos
        if (A + B == 0 || A + C == 0 || B + C == 0) possible = 1;
        if (A - B == 0 || A - C == 0 || B - C == 0) possible = 1;

        // Usando três créditos
        if (A + B + C == 0 || A - B - C == 0 || B - A - C == 0 || C - A - B == 0) possible = 1;

        // Imprimir resultado
        if (possible) {
            printf("S\n");
        } else {
            printf("N\n");
        }
    }
    
    return 0;
}
