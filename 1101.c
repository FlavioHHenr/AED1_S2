#include <stdio.h>

int main() {
    int M, N;

    while (1) {
        // Leitura dos valores M e N
        scanf("%d %d", &M, &N);

        // Verificação da condição de parada
        if (M <= 0 || N <= 0) {
            break;
        }

        // Inicializar variáveis para calcular o menor e maior
        int menor = M < N ? M : N;
        int maior = M > N ? M : N;
        int soma = 0;

        // Exibir a sequência e calcular a soma
        for (int i = menor; i <= maior; i++) {
            printf("%d ", i);
            soma += i;
        }
        printf("Sum=%d\n", soma);
    }

    return 0;
}
