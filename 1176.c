#include <stdio.h>

// Função para calcular o N-ésimo número de Fibonacci
unsigned long long fibonacci(int n) {
    unsigned long long fib[61]; // Array para armazenar valores de Fibonacci até Fib(60)
    fib[0] = 0;
    fib[1] = 1;
    
    // Preenche o array com os valores de Fibonacci
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    
    return fib[n];
}

int main() {
    int T;
    scanf("%d", &T); // Ler o número de casos de teste

    for (int i = 0; i < T; i++) {
        int N;
        scanf("%d", &N); // Ler o índice de Fibonacci a ser calculado
        printf("Fib(%d) = %llu\n", N, fibonacci(N)); // Imprimir o resultado
    }

    return 0;
}
