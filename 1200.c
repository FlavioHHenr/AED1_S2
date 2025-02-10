#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Estrutura para o nó da árvore
typedef struct Node {
    char data;
    struct Node *left;
    struct Node *right;
} Node;

// Função para criar um novo nó
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para inserir um novo nó na árvore binária de busca
Node* insert(Node* root, char data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Função para fazer o percurso infixo
void infix(Node* root) {
    if (root != NULL) {
        infix(root->left);
        printf("%c ", root->data);
        infix(root->right);
    }
}

// Função para fazer o percurso prefixo
void prefix(Node* root) {
    if (root != NULL) {
        printf("%c ", root->data);
        prefix(root->left);
        prefix(root->right);
    }
}

// Função para fazer o percurso posfixo
void postfix(Node* root) {
    if (root != NULL) {
        postfix(root->left);
        postfix(root->right);
        printf("%c ", root->data);
    }
}

// Função para pesquisar um elemento na árvore
bool search(Node* root, char data) {
    if (root == NULL) {
        return false;
    }
    if (root->data == data) {
        return true;
    }
    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

int main() {
    Node* root = NULL;
    char command[20];
    char data;
    
    while (scanf("%s", command) != EOF) {
        if (command[0] == 'I') {
            // Inserção de um novo nó
            sscanf(command, "I %c", &data);
            root = insert(root, data);
        } else if (strcmp(command, "INFIXA") == 0) {
            // Percurso infixo
            infix(root);
            printf("\n");
        } else if (strcmp(command, "PREFIXA") == 0) {
            // Percurso prefixo
            prefix(root);
            printf("\n");
        } else if (strcmp(command, "POSFIXA") == 0) {
            // Percurso posfixo
            postfix(root);
            printf("\n");
        } else if (command[0] == 'P') {
            // Pesquisa de um elemento
            sscanf(command, "P %c", &data);
            if (search(root, data)) {
                printf("%c existe\n", data);
            } else {
                printf("%c nao existe\n", data);
            }
        }
    }

    return 0;
}
