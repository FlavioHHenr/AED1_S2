#include <stdio.h>

// Função para encontrar o maior lado
int max(int a, int b, int c) {
    if (a >= b && a >= c) return a;
    if (b >= a && b >= c) return b;
    return c;
}

// Função para encontrar o menor lado
int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

// Função para encontrar o lado do meio
int mid(int a, int b, int c) {
    if ((a > b && a < c) || (a < b && a > c)) return a;
    if ((b > a && b < c) || (b < a && b > c)) return b;
    return c;
}

int main() {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);

    // Verifica se é um triângulo válido
    if (A + B > C && A + C > B && B + C > A) {
        // Verifica o tipo de triângulo
        if (A == B && B == C) {
            printf("Valido-Equilatero\n");
        } else if (A == B || A == C || B == C) {
            printf("Valido-Isoceles\n");
        } else {
            printf("Valido-Escaleno\n");
        }

        // Verifica se o triângulo é retângulo
        int max_side = max(A, B, C);
        int side1 = min(A, B, C);
        int side2 = mid(A, B, C);

        if (max_side * max_side == side1 * side1 + side2 * side2) {
            printf("Retangulo: S\n");
        } else {
            printf("Retangulo: N\n");
        }
    } else {
        printf("Invalido\n");
    }

    return 0;
}
