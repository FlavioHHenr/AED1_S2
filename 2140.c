#include <stdio.h>
int verificar_troco(int troco) {
    // Notas disponíveis
    int notas[] = {2, 5, 10, 20, 50, 100};
    int n_notas = sizeof(notas) / sizeof(notas[0]);

    // Verifica todas as combinações de duas notas
    for (int i = 0; i < n_notas; i++) {
        for (int j = i; j < n_notas; j++) {
            if (notas[i] + notas[j] == troco) {
                return 1;  // Possível devolver o troco
            }
        }
    }
    return 0;  // Não é possível devolver o troco
}

int main() {
    int N, M;

    // Leitura dos casos de teste
    while (scanf("%d %d", &N, &M) && (N != 0 || M != 0)) {
        int troco = M - N;

        if (verificar_troco(troco)) {
            printf("possible\n");
        } else {
            printf("impossible\n");
        }
    }

    return 0;
}
