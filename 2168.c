#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    
    // Criar a matriz de câmeras (N+1)x(N+1)
    int cameras[N+1][N+1];
    
    // Ler a matriz de câmeras
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            scanf("%d", &cameras[i][j]);
        }
    }
    
    // Determinar o status de cada quadra
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // Checar câmeras nas quatro esquinas da quadra
            int count = 0;
            count += cameras[i][j];          // Canto superior esquerdo
            count += cameras[i][j+1];        // Canto superior direito
            count += cameras[i+1][j];        // Canto inferior esquerdo
            count += cameras[i+1][j+1];      // Canto inferior direito
            
            // Se pelo menos duas câmeras estão presentes
            if (count >= 2) {
                printf("S");
            } else {
                printf("U");
            }
        }
        printf("\n");
    }
    
    return 0;
}
