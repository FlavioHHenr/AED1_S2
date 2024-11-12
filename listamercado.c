#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista_compra {
    char item[21]; // Cada item pode ter até 20 caracteres, mais o caractere nulo
    struct lista_compra *proximo;
} Lista;

void inserir_ordenado(Lista **lista, char *novo_item) {
    Lista *aux, *novo = malloc(sizeof(Lista));

    if (novo) {
        strcpy(novo->item, novo_item);
        novo->proximo = NULL;

        // Lista vazia ou item é menor que o primeiro
        if (*lista == NULL || strcmp(novo->item, (*lista)->item) < 0) {
            novo->proximo = *lista;
            *lista = novo;
        } else {
            aux = *lista;
            // Percorre a lista para manter a ordem alfabética e evitar duplicatas
            while (aux->proximo && strcmp(novo->item, aux->proximo->item) > 0) {
                aux = aux->proximo;
            }

            // Verifica duplicata
            if (strcmp(aux->item, novo->item) == 0 ||
               (aux->proximo && strcmp(aux->proximo->item, novo->item) == 0)) {
                free(novo); // Ignora duplicatas
            } else {
                novo->proximo = aux->proximo;
                aux->proximo = novo;
            }
        }
    } else {
        printf("Erro ao alocar memória!\n");
    }
}

void liberar_lista(Lista *lista) {
    Lista *aux;
    while (lista) {
        aux = lista;
        lista = lista->proximo;
        free(aux);
    }
}

void imprimir_lista(Lista *lista) {
    Lista *aux = lista;
    while (aux) {
        printf("%s", aux->item);
        aux = aux->proximo;
        if (aux) printf(" ");
    }
    printf("\n");
}

int main() {
    int N;
    scanf("%d\n", &N);  // Lê o número de listas de compras

    for (int i = 0; i < N; i++) {
        Lista *lista = NULL;
        char linha[21000]; // Para até 1000 itens com no máximo 20 caracteres cada

        // Lê a linha de itens da lista de compras
        fgets(linha, sizeof(linha), stdin);

        // Divide a linha em itens individuais
        char *item = strtok(linha, " \n");
        while (item != NULL) {
            inserir_ordenado(&lista, item);
            item = strtok(NULL, " \n");
        }

        // Imprime a lista em ordem e sem duplicatas
        imprimir_lista(lista);

        // Libera a lista
        liberar_lista(lista);
    }

    return 0;
}
