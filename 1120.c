#include <stdio.h>
#include <string.h>

int main() {
    char D, N[101]; // D é o dígito que falha, N é o número original.
    
    while (1) {
        scanf(" %c %s", &D, N);
        
        // Condição de término
        if (D == '0' && strcmp(N, "0") == 0) {
            break;
        }

        char result[101] = "";
        int pos = 0;

        // Percorrer o número e ignorar o dígito D
        for (int i = 0; N[i] != '\0'; i++) {
            if (N[i] != D) {
                result[pos++] = N[i];
            }
        }

        // Terminar a string resultante
        result[pos] = '\0';

        // Converter o resultado para inteiro e remover zeros à esquerda
        // Se o resultado for vazio, imprimir "0"
        if (strlen(result) == 0) {
            printf("0\n");
        } else {
            // Se result não tiver zeros à esquerda
            long long valor = atoll(result); // Convertendo para inteiro longo
            printf("%lld\n", valor);
        }
    }

    return 0;
}
