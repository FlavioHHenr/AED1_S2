#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        double C;
        scanf("%lf", &C);

        int dias = 0;
        while (C > 1.0) {
            C /= 2;
            dias++;
        }

        printf("%d dias\n", dias);
    }

    return 0;
}
