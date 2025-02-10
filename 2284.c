#include <stdio.h>

int main() {
    int H, P;
    
    // Ler os valores de H e P
    while (scanf("%d %d", &H, &P) != EOF) {
        // Calcula a média
        double media = (double)H / P;
        
        // Imprime a média formatada com duas casas decimais
        printf("%.2f\n", media);
    }
    
    return 0;
}
