#include <stdio.h>

int main() {
    int L, velocidade;
    
    while (scanf("%d", &L) != EOF) {
        int max_velocidade = 0;

        // Leitura das velocidades das lesmas
        for (int i = 0; i < L; i++) {
            scanf("%d", &velocidade);
            if (velocidade > max_velocidade) {
                max_velocidade = velocidade;
            }
        }

        // Determinar o nível da lesma mais veloz
        if (max_velocidade < 10) {
            printf("1\n");
        } else if (max_velocidade < 20) {
            printf("2\n");
        } else {
            printf("3\n");
        }
    }

    return 0;
}
