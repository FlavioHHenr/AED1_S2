#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define verdadeiro 1
#define falso 0

typedef struct No{

	long long valor;
	struct No *proximoNo;

} No;

typedef struct Pilha{

	No *topoPilha;

} Pilha;


void desempilhar(Pilha *p);
void inicializarPilha(Pilha *p);
long long encontrarMenor(Pilha *p);
void empilhar(Pilha *p, long long valor);

void main ()
{

	Pilha p;
	char operacao[10];
	unsigned qtdOperacoes;
	long long valor, temporario;

	scanf("%u", &qtdOperacoes);

	inicializarPilha(&p);

	while (qtdOperacoes--)
	{

		scanf("%s", operacao);

		if (strcmp(operacao, "PUSH") == 0)
		{

			scanf("%lld", &valor);
			empilhar(&p, valor);

		}
		else if (strcmp(operacao, "POP") == 0)
			desempilhar(&p);
		else
		{

			temporario = encontrarMenor(&p);
			if (temporario == -1)
				printf("EMPTY\n");
			else
				printf("%lld\n", temporario);

		}

	}

}

void inicializarPilha(Pilha *p)
{

	p->topoPilha = NULL;

}

void empilhar(Pilha *p, long long valor)
{

	No *novoNo;

	novoNo = (No *) malloc(sizeof(No));

	if (!novoNo)
		exit(1);

	novoNo->proximoNo = p->topoPilha;
	p->topoPilha = novoNo;
	novoNo->valor = valor;

}

void desempilhar(Pilha *p)
{

	No *temporario;
	temporario = p->topoPilha;

	if (temporario)
	{

		p->topoPilha = temporario->proximoNo;
		free(temporario);

	}
	else
		printf("EMPTY\n");

}

long long encontrarMenor(Pilha *p)
{

	No *temporario;
	temporario = p->topoPilha;

	if (!temporario)
		return -1;

	long long menorValor = temporario->valor;

	while (temporario)
	{

		if (temporario->valor < menorValor)
			menorValor = temporario->valor;

		temporario = temporario->proximoNo;

	}

	return menorValor;

}
