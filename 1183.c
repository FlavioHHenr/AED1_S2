#include <stdio.h>

int main() {
    char O;
    double M[12][12], soma = 0.0;
    int contador = 0;

    // Leitura da operação O (Soma ou Média)
    scanf("%c", &O);

    // Leitura dos elementos da matriz M[12][12]
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            scanf("%lf", &M[i][j]);
        }
    }

    // Calcular a soma dos elementos acima da diagonal principal
    for (int i = 0; i < 12; i++) {
        for (int j = i + 1; j < 12; j++) { // Começa em j = i + 1 para pegar os elementos acima da diagonal principal
            soma += M[i][j];
            contador++;
        }
    }

    // Verificar se a operação é soma ou média
    if (O == 'S') {
        printf("%.1lf\n", soma);
    } else if (O == 'M') {
        printf("%.1lf\n", soma / contador);
    }

    return 0;
}
