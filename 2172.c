#include <stdio.h>

int main() {
    int X, M;

    while (1) {
        // Leitura dos valores X e M
        scanf("%d %d", &X, &M);
        
        // Verifica o caso de término
        if (X == 0 && M == 0) {
            break;
        }
        
        // Calcula o novo valor de EXP
        long long E = (long long)X * M;
        
        // Imprime o resultado
        printf("%lld\n", E);
    }

    return 0;
}
