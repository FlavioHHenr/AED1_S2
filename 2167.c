#include <stdio.h>

int main() {
    int N; // Número de medidas
    int velocities[100]; // Array para armazenar as medidas de velocidade

    // Lê o número de medidas
    scanf("%d", &N);

    // Lê as medidas de velocidade
    for (int i = 0; i < N; i++) {
        scanf("%d", &velocities[i]);
    }

    // Verifica a primeira ocorrência de queda de velocidade
    int first_drop_index = 0; // Inicializa com 0 (nenhuma queda encontrada ainda)
    for (int i = 1; i < N; i++) {
        if (velocities[i] < velocities[i - 1]) {
            first_drop_index = i + 1; // Índice deve ser 1-based
            break;
        }
    }

    // Imprime o índice da primeira queda ou 0 se nenhuma queda for encontrada
    printf("%d\n", first_drop_index);

    return 0;
}
