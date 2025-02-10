#include <stdio.h>

// Função para calcular se é o Natal, véspera de Natal, já passou ou quantos dias faltam
void dias_para_natal(int mes, int dia) {
    // Data do Natal
    int natal_mes = 12;
    int natal_dia = 25;

    // Funções auxiliares para calcular o número de dias em cada mês
    int dias_no_mes[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Função para calcular o número total de dias do início do ano até uma data
    int dias_ate_data(int m, int d) {
        int dias = 0;
        for (int i = 0; i < m - 1; i++) {
            dias += dias_no_mes[i];
        }
        dias += d;
        return dias;
    }

    // Calcula o número total de dias desde o início do ano até a data fornecida e o Natal
    int dias_data = dias_ate_data(mes, dia);
    int dias_natal = dias_ate_data(natal_mes, natal_dia);

    // Calcula a diferença entre as datas
    int diferenca = dias_natal - dias_data;

    if (diferenca == 0) {
        printf("E natal!\n");
    } else if (diferenca == 1) {
        printf("E vespera de natal!\n");
    } else if (diferenca < 0) {
        printf("Ja passou!\n");
    } else {
        printf("Faltam %d dias para o natal!\n", diferenca);
    }
}

int main() {
    int mes, dia;
    
    while (scanf("%d %d", &mes, &dia) != EOF) {
        dias_para_natal(mes, dia);
    }
    
    return 0;
}
