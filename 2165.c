#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 500

int main() {
    char text[MAX_LENGTH + 1]; // Array para armazenar a linha de texto

    // Lê a linha de texto
    fgets(text, sizeof(text), stdin);

    // Remove o caractere de nova linha se presente
    size_t length = strlen(text);
    if (length > 0 && text[length - 1] == '\n') {
        text[length - 1] = '\0';
    }

    // Verifica o comprimento do texto
    if (strlen(text) <= 140) {
        printf("TWEET\n");
    } else {
        printf("MUTE\n");
    }

    return 0;
}
