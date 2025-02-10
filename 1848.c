#include <stdio.h>
#include <string.h>

// Função para converter a piscada em um número binário
int piscadaParaNumero(const char* piscada) {
    int numero = 0;
    if (piscada[0] == '*') numero += 4; // bit mais significativo
    if (piscada[1] == '*') numero += 2;
    if (piscada[2] == '*') numero += 1; // bit menos significativo
    return numero;
}

int main() {
    char linha[10];
    int soma = 0;
    int resultados[3];
    int resultadoIndex = 0;
    
    // Inicializa o array de resultados com zeros
    for (int i = 0; i < 3; i++) {
        resultados[i] = 0;
    }

    while (fgets(linha, sizeof(linha), stdin)) {
        linha[strcspn(linha, "\n")] = '\0'; // Remove o newline do final da string
        
        if (strcmp(linha, "caw caw") == 0) {
            // Quando encontramos um "caw caw", armazenamos o resultado da soma atual
            resultados[resultadoIndex] = soma;
            resultadoIndex++;
            soma = 0; // Reseta a soma para o próximo número
        } else {
            // Converte a piscada em número e adiciona à soma
            soma += piscadaParaNumero(linha);
        }
    }

    // Imprime os resultados
    for (int i = 0; i < 3; i++) {
        printf("%d\n", resultados[i]);
    }

    return 0;
}
