#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N); // Lê o número de jogadores

    // Variáveis para acumular tentativas e sucessos
    int totalS = 0, totalB = 0, totalA = 0;
    int totalS1 = 0, totalB1 = 0, totalA1 = 0;

    for (int i = 0; i < N; i++) {
        char nome[100];
        scanf("%s", nome); // Lê o nome do jogador

        // Lê tentativas
        int S, B, A;
        scanf("%d %d %d", &S, &B, &A);

        // Lê sucessos
        int S1, B1, A1;
        scanf("%d %d %d", &S1, &B1, &A1);

        // Atualiza totais
        totalS += S;
        totalB += B;
        totalA += A;

        totalS1 += S1;
        totalB1 += B1;
        totalA1 += A1;
    }

    // Calcula e imprime os percentuais
    double percentS = (totalS > 0) ? (100.0 * totalS1 / totalS) : 0.0;
    double percentB = (totalB > 0) ? (100.0 * totalB1 / totalB) : 0.0;
    double percentA = (totalA > 0) ? (100.0 * totalA1 / totalA) : 0.0;

    printf("Pontos de Saque: %.2f %%.\n", percentS);
    printf("Pontos de Bloqueio: %.2f %%.\n", percentB);
    printf("Pontos de Ataque: %.2f %%.\n", percentA);

    return 0;
}
