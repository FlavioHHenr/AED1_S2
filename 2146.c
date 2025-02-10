#include <stdio.h>

int main() {
    int N;

    // Lê a entrada até o fim do arquivo
    while (scanf("%d", &N) != EOF) {
        // Calcula a senha como N - 1
        printf("%d\n", N - 1);
    }

    return 0;
}
