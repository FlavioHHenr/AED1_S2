#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define GRAMS_PER_KG 1000
#define GRAINS_PER_GRAM 12
#define GRAINS_PER_KG (GRAMS_PER_KG * GRAINS_PER_GRAM)

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int X;
        scanf("%d", &X);
        
        // Calcula o total de grãos como 2^X - 1
        uint64_t totalGrains = (1ULL << X) - 1;

        // Calcula a quantidade de kg
        uint64_t totalKg = totalGrains / GRAINS_PER_KG;

        // Imprime o resultado
        printf("%llu kg\n", totalKg);
    }

    return 0;
}
