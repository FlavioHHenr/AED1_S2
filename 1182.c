#include <stdio.h>

int main() {
    int C;
    char T;
    double M[12][12], soma = 0.0;

    // Leitura da coluna C e da operação T
    scanf("%d", &C);
    scanf(" %c", &T); // O espaço antes de %c é para ignorar o enter anterior

    // Leitura dos elementos da matriz M
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            scanf("%lf", &M[i][j]);
        }
    }

    // Calcula a soma dos elementos da coluna C
    for (int i = 0; i < 12; i++) {
        soma += M[i][C];
    }

    // Verifica se a operação é soma ou média
    if (T == 'S') {
        printf("%.1lf\n", soma);
    } else if (T == 'M') {
        printf("%.1lf\n", soma / 12.0);
    }

    return 0;
}
