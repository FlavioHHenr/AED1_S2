#include <stdio.h>
#include <math.h>

int main() {
    int A, B, C;

    while (1) {
        // Leitura dos valores A, B e C
        scanf("%d %d %d", &A, &B, &C);

        // Condição de parada
        if (A == 0 || B == 0 || C == 0) {
            break;
        }

        // Calcula a área da casa
        int area_casa = A * B;

        // Calcula o lado mínimo do terreno necessário
        double lado_terreno = sqrt((double)area_casa * 100 / C);

        // Imprime o lado truncado do terreno
        printf("%d\n", (int)lado_terreno);
    }

    return 0;
}
