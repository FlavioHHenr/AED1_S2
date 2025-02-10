#include <stdio.h>

int verifica_linha_coluna(int matriz[9][9]) {
    int i, j;

    // Verificar linhas
    for (i = 0; i < 9; i++) {
        int linha[10] = {0};
        for (j = 0; j < 9; j++) {
            linha[matriz[i][j]]++;
            if (linha[matriz[i][j]] > 1) return 0;
        }
    }

    // Verificar colunas
    for (j = 0; j < 9; j++) {
        int coluna[10] = {0};
        for (i = 0; i < 9; i++) {
            coluna[matriz[i][j]]++;
            if (coluna[matriz[i][j]] > 1) return 0;
        }
    }

    return 1;
}

int verifica_submatrizes_3x3(int matriz[9][9]) {
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            int contagem[10] = {0};

            for (int m = 0; m < 3; m++) {
                for (int n = 0; n < 3; n++) {
                    int num = matriz[i + m][j + n];
                    contagem[num]++;
                    if (contagem[num] > 1) return 0;
                }
            }
        }
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n); // Número de instâncias

    for (int k = 1; k <= n; k++) { // Lendo todas as instâncias
        int sudoku[9][9];

        // Lendo a matriz do Sudoku
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &sudoku[i][j]);
            }
        }

        // Verificações para cada instância
        printf("Instancia %d\n", k);
        if (verifica_linha_coluna(sudoku) && verifica_submatrizes_3x3(sudoku)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        if (k < n) {
            printf("\n"); // Adiciona uma linha em branco apenas entre as instâncias
        }
    }

    return 0;
}
