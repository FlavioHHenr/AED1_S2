#include <stdio.h>
#include <stdlib.h>

int main() {
    int hashmat, opponent;

    // Leitura até o final do arquivo (EOF)
    while (scanf("%d %d", &hashmat, &opponent) != EOF) {
        // Calcula a diferença absoluta entre os soldados
        int difference = abs(hashmat - opponent);
        // Imprime o resultado
        printf("%d\n", difference);
    }

    return 0;
}
