#include <stdio.h>
#include <string.h>

int main() {
    int C;
    scanf("%d", &C);  // Lê o número de casos de teste

    while (C--) {
        char word[10001];  // Palavra com até 10000 letras + 1 para o terminador de string
        scanf("%s", word);  // Lê a palavra
        
        int len = strlen(word);  // Comprimento da palavra
        int pressCount = 0;  // Contador de pressionamentos

        // Itera sobre a palavra para contar o número de pressionamentos
        for (int i = 0; i < len; i++) {
            if (i == 0 || word[i] != word[i - 1]) {
                pressCount++;
            }
        }

        // Calcula o tempo gasto
        double timeSpent = pressCount * 0.01;

        // Imprime o tempo gasto formatado com 2 casas decimais
        printf("%.2f\n", timeSpent);
    }

    return 0;
}
