#include <stdio.h>

int main() {
    int I;
    
    // Ler o índice de felicidade
    scanf("%d", &I);
    
    // Imprimir "Feliz nat"
    printf("Feliz nat");
    
    // Imprimir 'a' repetidamente, I vezes
    for (int i = 0; i < I; i++) {
        printf("a");
    }
    
    // Imprimir "l!"
    printf("l!\n");
    
    return 0;
}
