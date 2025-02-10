#include <stdio.h>
#include <stdlib.h>

typedef struct no_lista{

	int valor;
	struct no_lista *proximo;

} NoLista;

typedef struct lista_encadeada{

	NoLista *primeiro;
	NoLista *ultimo;

} ListaEncadeada;

void inserir_na_hash(ListaEncadeada *, const int);
unsigned tamanhoHash;

int main()
{
	unsigned quantidadeTestes;
	NoLista *noAtual;
	int quantidadeElementos, contador, elementoTemporario;

	scanf("%u", &quantidadeTestes);

	while (quantidadeTestes--)
	{
		scanf("%u %d", &tamanhoHash, &quantidadeElementos);

		ListaEncadeada tabelaHash[tamanhoHash];
		for (contador = 0; contador < tamanhoHash; ++contador)
		{
			tabelaHash[contador].primeiro = NULL;
			tabelaHash[contador].ultimo = NULL;
		}

		for (contador = 0; contador < quantidadeElementos; ++contador)
		{
			scanf("%d", &elementoTemporario);
			inserir_na_hash(tabelaHash, elementoTemporario);
		}

		for (contador = 0; contador < tamanhoHash; ++contador)
		{	
			printf("%d -> ", contador);
			for (noAtual = tabelaHash[contador].primeiro; noAtual; noAtual = noAtual->proximo)
				printf("%d -> ", noAtual->valor);

			printf("\\");
			printf("\n");
		}

		if (quantidadeTestes)
			printf("\n");
	}

	return 0; 
}

void inserir_na_hash(ListaEncadeada *tabelaHash, const int chave)
{
	NoLista *novoNo;
	novoNo = (NoLista *) malloc(sizeof(NoLista));

	if(!novoNo)
		exit(1);

	int indice = chave % tamanhoHash;
	if (tabelaHash[indice].primeiro)
		tabelaHash[indice].ultimo->proximo = novoNo;
	else
		tabelaHash[indice].primeiro = novoNo;

	tabelaHash[indice].ultimo = novoNo;
	novoNo->proximo = NULL;
	novoNo->valor = chave;
}
