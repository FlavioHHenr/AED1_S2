#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);  // Ler o número de casos de teste
    
    for (int i = 0; i < T; i++) {
        int H, M, O;
        scanf("%d %d %d", &H, &M, &O);  // Ler hora, minuto e ocorrência
        
        // Formatar a hora e minuto com dois dígitos
        printf("%02d:%02d - ", H, M);
        
        // Imprimir a mensagem baseada na ocorrência
        if (O == 1) {
            printf("A porta abriu!\n");
        } else {
            printf("A porta fechou!\n");
        }
    }
    
    return 0;
}
