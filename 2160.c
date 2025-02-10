#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 80

int main() {
    char line[501];  // Linha de texto com até 500 caracteres + 1 para o terminador de string

    // Lê a linha de texto
    fgets(line, sizeof(line), stdin);

    // Remove o caractere de nova linha no final da linha lida
    size_t length = strlen(line);
    if (length > 0 && line[length - 1] == '\n') {
        line[length - 1] = '\0';
        length--;
    }

    // Verifica se o comprimento da linha é menor ou igual a 80
    if (length <= MAX_LENGTH) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
