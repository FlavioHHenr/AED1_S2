#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int grade[9][9], validador[10], n, x, y, z, h, invalido;

    scanf("%d", &n);

    for (h = 1; h <= n; h++) {
        invalido = 0;

        // Lê a grade do Sudoku
        for (x = 0; x < 9; x++) {
            for (y = 0; y < 9; y++) {
                scanf("%d", &grade[x][y]);
            }
        }

        // Valida as linhas
        for (x = 0; x < 9 && !invalido; x++) {
            memset(validador, 0, sizeof(validador));
            for (y = 0; y < 9 && !invalido; y++) {
                if (validador[grade[x][y]]) {
                    invalido = 1;
                } else {
                    validador[grade[x][y]] = 1;
                }
            }
        }

        // Valida as colunas
        for (y = 0; y < 9 && !invalido; y++) {
            memset(validador, 0, sizeof(validador));
            for (x = 0; x < 9 && !invalido; x++) {
                if (validador[grade[x][y]]) {
                    invalido = 1;
                } else {
                    validador[grade[x][y]] = 1;
                }
            }
        }

        // Valida os blocos 3x3
        for (x = 0; x < 9 && !invalido; x += 3) {
            for (y = 0; y < 9 && !invalido; y += 3) {
                memset(validador, 0, sizeof(validador));
                for (z = 0; z < 9 && !invalido; z++) {
                    int linhaBloco = x + z / 3;
                    int colunaBloco = y + z % 3;
                    if (validador[grade[linhaBloco][colunaBloco]]) {
                        invalido = 1;
                    } else {
                        validador[grade[linhaBloco][colunaBloco]] = 1;
                    }
                }
            }
        }

        // Exibe o resultado
        printf("Instancia %d\n", h);
        printf("%s\n\n", invalido ? "NAO" : "SIM");
    }

    return 0;
}
