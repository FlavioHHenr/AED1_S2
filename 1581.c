#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() 
{
	unsigned short quantidadeCasos, quantidadePessoas;
	char palavraAtual[21], palavraAnterior[21];
	bool idiomaIngles;

	scanf("%hu", &quantidadeCasos);

	while (quantidadeCasos--)
	{
		scanf("%hu", &quantidadePessoas);

		scanf(" %s", palavraAtual);

		quantidadePessoas--;
		idiomaIngles = false;
		strcpy(palavraAnterior, palavraAtual);

		while (quantidadePessoas--)
		{
			if (strcmp(palavraAtual, palavraAnterior) != 0 && idiomaIngles == false)
				idiomaIngles = true;
			else
				strcpy(palavraAnterior, palavraAtual);

			scanf(" %s", palavraAtual);
		}

		if (idiomaIngles)
			printf("ingles\n");
		else
			printf("%s\n", palavraAtual);

		idiomaIngles = false;
	}

	return 0; 
}
