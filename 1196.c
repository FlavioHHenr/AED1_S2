#include <stdio.h>
#include <string.h>

// Função para criar o mapeamento dos caracteres
void create_mapping(char *mapping) {
    // Mapeamento das teclas deslocadas para a tecla correta
    mapping['W'] = 'Q'; mapping['E'] = 'W'; mapping['R'] = 'E';
    mapping['T'] = 'R'; mapping['Y'] = 'T'; mapping['U'] = 'Y';
    mapping['I'] = 'U'; mapping['O'] = 'I'; mapping['P'] = 'O';
    mapping['['] = 'P'; mapping[']'] = '['; mapping['\\'] = ']';
    mapping['S'] = 'A'; mapping['D'] = 'S'; mapping['F'] = 'D';
    mapping['G'] = 'F'; mapping['H'] = 'G'; mapping['J'] = 'H';
    mapping['K'] = 'J'; mapping['L'] = 'K'; mapping[';'] = 'L';
    mapping['\''] = ';'; mapping['X'] = 'Z'; mapping['C'] = 'X';
    mapping['V'] = 'C'; mapping['B'] = 'V'; mapping['N'] = 'B';
    mapping['M'] = 'N'; mapping[','] = 'M'; mapping['.'] = ',';
    mapping['/'] = '.';
    
    // Caracteres não mapeados devem se mapear para si mesmos
    for (int i = 0; i < 256; i++) {
        if (mapping[i] == '\0') {
            mapping[i] = i;
        }
    }
}

// Função para decodificar uma linha com base no mapeamento
void decode_line(const char *input, char *output, char *mapping) {
    while (*input) {
        output[0] = mapping[(unsigned char)*input];
        output++;
        input++;
    }
    output[0] = '\0'; // Finaliza a string de saída
}

int main() {
    char mapping[256] = {0};
    char input[1024];
    char output[1024];

    // Cria o mapeamento dos caracteres
    create_mapping(mapping);

    // Lê as linhas de entrada e processa até EOF
    while (fgets(input, sizeof(input), stdin)) {
        // Remove o caractere de nova linha, se houver
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        // Decodifica a linha
        decode_line(input, output, mapping);

        // Imprime a linha decodificada
        printf("%s\n", output);
    }

    return 0;
}
