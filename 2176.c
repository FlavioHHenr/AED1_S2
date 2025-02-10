#include <stdio.h>
#include <string.h>

int main() {
    char mensagem[101]; // Buffer para armazenar a mensagem binária
    while (fgets(mensagem, sizeof(mensagem), stdin)) {
        // Remove o caractere de nova linha, se presente
        mensagem[strcspn(mensagem, "\n")] = '\0';
        
        // Calcula o número de bits '1'
        int count1 = 0;
        for (int i = 0; i < strlen(mensagem); i++) {
            if (mensagem[i] == '1') {
                count1++;
            }
        }

        // Determina o bit de paridade
        char bitParidade = (count1 % 2 == 0) ? '0' : '1';

        // Imprime a mensagem com o bit de paridade
        printf("%s%c\n", mensagem, bitParidade);
    }

    return 0;
}
