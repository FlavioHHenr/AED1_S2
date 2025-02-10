#include <stdio.h>

int main() {
    int N; // Número de casos de teste
    scanf("%d", &N);

    while (N--) {
        int X; // Valor a ser analisado
        scanf("%d", &X);

        if (X == 0) {
            printf("NULL\n");
        } else {
            if (X % 2 == 0) {
                printf("EVEN ");
            } else {
                printf("ODD ");
            }

            if (X > 0) {
                printf("POSITIVE\n");
            } else {
                printf("NEGATIVE\n");
            }
        }
    }

    return 0;
}
