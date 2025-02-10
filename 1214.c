#include <stdio.h>

int main() {
    int C;
    scanf("%d", &C); // Leitura do número de casos de teste

    while (C--) {
        int N;
        scanf("%d", &N); // Leitura do número de pessoas na turma

        int scores[N];
        int sum = 0;

        // Leitura das médias finais e cálculo da soma
        for (int i = 0; i < N; i++) {
            scanf("%d", &scores[i]);
            sum += scores[i];
        }

        double average = (double)sum / N; // Cálculo da média da turma
        int above_average_count = 0;

        // Contar quantos estudantes estão acima da média
        for (int i = 0; i < N; i++) {
            if (scores[i] > average) {
                above_average_count++;
            }
        }

        // Cálculo do percentual de estudantes acima da média
        double percentage = (double)above_average_count / N * 100;

        // Impressão do resultado com 3 casas decimais
        printf("%.3f%%\n", percentage);
    }

    return 0;
}
