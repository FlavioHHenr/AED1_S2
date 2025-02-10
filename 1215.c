#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct{
	char palavra[201];
} String;

bool buscarString(char *, String *, unsigned);
void quickSortParcial(String *dicionario, int tamanho);
void quickSortInterno(String *dicionario, int inicio, int fim);

int main()
{
	unsigned indiceEntrada, indiceSaida, quantidadePalavras = 0;

	// Vetores para guardar temporariamente uma string;
	char entradaTemporaria[201], saidaTemporaria[201];
	// Vetor onde irão ficar as palavras do dicionário;
	String dicionario[5050];

	memset(dicionario, 0, sizeof(dicionario));
	while (scanf(" %[^\n]", entradaTemporaria) != EOF)
	{
		indiceEntrada = indiceSaida = 0;
		while (entradaTemporaria[indiceEntrada])
		{
			// Enquanto o caractere na posição atual da string for uma letra;
			// O passe para a string temporária de saída já em minúsculo;
			while (isalpha(entradaTemporaria[indiceEntrada]))
				saidaTemporaria[indiceSaida++] = tolower(entradaTemporaria[indiceEntrada++]);

			// Se o caractere que fez o laço acima sair foi o caractere nulo
			// Significa que a string chegou no fim
			// Por isso deve-se executar todos os procedimentos de procura e inserção no dicionário;
			// Logo em seguida, quebra-se o laço mais externo;
			if (entradaTemporaria[indiceEntrada] == '\0')
			{
				saidaTemporaria[indiceSaida] = '\0';

				if (!buscarString(saidaTemporaria, dicionario, quantidadePalavras))
					strcpy(dicionario[quantidadePalavras++].palavra, saidaTemporaria);

				indiceSaida = 0;

				memset(saidaTemporaria, 0, sizeof(saidaTemporaria));
				break;
			}

			saidaTemporaria[indiceSaida] = '\0';

			// Enquanto o caractere atual não for uma letra, apenas avance;
			while (!isalpha(entradaTemporaria[indiceEntrada]))
			{
				indiceEntrada++;
				// Caso o caractere na posição atual seja o caractere nulo;
				// Significa que a string acabou, pare o laço;
				if (entradaTemporaria[indiceEntrada] == '\0')
					break;
			}

			// Se a palavra contida na string temporária ainda não existe
			// No struct das strings de saída, então a coloque lá;
			if (!buscarString(saidaTemporaria, dicionario, quantidadePalavras))
				strcpy(dicionario[quantidadePalavras++].palavra, saidaTemporaria);

			indiceSaida = 0;
			memset(saidaTemporaria, 0, sizeof(saidaTemporaria));
		}

		memset(entradaTemporaria, 0, sizeof(entradaTemporaria));
	}

	quickSortParcial(dicionario, quantidadePalavras);

	indiceSaida = 0;
	// Pode haver uma string nula na primeira posição do dicionário, se houver
	// Inicie 'indiceSaida' de 1;
	if (strcmp(dicionario[0].palavra, "\0") == 0)
		indiceSaida = 1;

	for (; indiceSaida < quantidadePalavras; indiceSaida++)
		printf("%s\n", dicionario[indiceSaida].palavra);

	return 0;
}

// Função de procura de uma string no dicionário;
bool buscarString(char *str, String *dicionario, unsigned tamanho)
{
	unsigned i;

	for (i = 0; i < tamanho; i++)
		if (strcmp(dicionario[i].palavra, str) == 0)
			return true;

	return false;
}

// QuickSort para ordenação em ordem alfabética;
void quickSortInterno(String *dicionario, int inicio, int fim)
{
	String pivo;
	String temporario;
	int indiceEsquerda, indiceDireita;

	if (fim - inicio > 0)
	{
		if (inicio < fim)
		{
			indiceEsquerda = inicio;
			indiceDireita = fim;
			pivo = dicionario[(indiceEsquerda + indiceDireita) / 2];

			do
			{
				while (strcmp(dicionario[indiceEsquerda].palavra, pivo.palavra) < 0)
					indiceEsquerda++;
				while (strcmp(dicionario[indiceDireita].palavra, pivo.palavra) > 0)
					indiceDireita--;

				if (indiceEsquerda <= indiceDireita)
				{
					temporario = dicionario[indiceEsquerda];
					dicionario[indiceEsquerda] = dicionario[indiceDireita];
					dicionario[indiceDireita] = temporario;
					indiceEsquerda++;
					indiceDireita--;
				}

			} while (indiceEsquerda <= indiceDireita);

			quickSortInterno(dicionario, inicio, indiceDireita);
			quickSortInterno(dicionario, indiceEsquerda, fim);
		}
	}
}

// Função que dispara a chamada recursiva;
void quickSortParcial(String *dicionario, int tamanho)
{
	quickSortInterno(dicionario, 0, tamanho - 1);
}
