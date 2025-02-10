#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    if (N <= 1) {
        printf("0\n");
        return 0;
    }

    int heights[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &heights[i]);
    }

    int is_valid = 1;
    int state = 0;  // 0: undefined, 1: expecting a peak, -1: expecting a valley

    for (int i = 1; i < N; i++) {
        if (heights[i] > heights[i - 1]) {
            // Current is a peak
            if (state == 1 || state == 0) {
                // Expected a peak or undefined
                state = -1;  // Next should be a valley
            } else {
                is_valid = 0;
                break;
            }
        } else if (heights[i] < heights[i - 1]) {
            // Current is a valley
            if (state == -1 || state == 0) {
                // Expected a valley or undefined
                state = 1;  // Next should be a peak
            } else {
                is_valid = 0;
                break;
            }
        } else {
            // No peak or valley (values are the same)
            is_valid = 0;
            break;
        }
    }

    printf("%d\n", is_valid);
    return 0;
}
