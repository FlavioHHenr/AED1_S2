#include <stdio.h>
#include <string.h>

// Função para determinar o resultado do jogo
const char* resultado(const char* sheldon, const char* raj) {
    // Regras do jogo em formato de matriz
    // 0 - empate
    // 1 - Sheldon ganha
    // -1 - Raj ganha
    const int resultados[5][5] = {
        /* pedra   papel   tesoura  lagarto  Spock */
        {0,      -1,       1,      1,      -1}, // pedra
        {1,       0,      -1,      -1,      1}, // papel
        {-1,      1,       0,      1,       -1}, // tesoura
        {-1,      1,      -1,      0,       1}, // lagarto
        {1,      -1,       1,     -1,       0}  // Spock
    };
    
    // Mapear as escolhas para índices
    char escolhas[5][10] = {"pedra", "papel", "tesoura", "lagarto", "Spock"};
    int indices[5];
    
    // Preencher a tabela de índices
    for (int i = 0; i < 5; i++) {
        indices[i] = i;
    }

    // Encontrar os índices das escolhas de Sheldon e Raj
    int s = -1, r = -1;
    for (int i = 0; i < 5; i++) {
        if (strcmp(sheldon, escolhas[i]) == 0) {
            s = i;
        }
        if (strcmp(raj, escolhas[i]) == 0) {
            r = i;
        }
    }

    if (s == r) {
        return "De novo!";
    } else if (resultados[s][r] == 1) {
        return "Bazinga!";
    } else {
        return "Raj trapaceou!";
    }
}

int main() {
    int T;
    scanf("%d", &T);
    getchar(); // Consumir o caractere de nova linha após o número de casos

    for (int i = 1; i <= T; i++) {
        char sheldon[10], raj[10];
        scanf("%s %s", sheldon, raj);
        const char* res = resultado(sheldon, raj);
        printf("Caso #%d: %s\n", i, res);
    }

    return 0;
}
