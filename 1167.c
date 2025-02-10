#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 31
#define MAX_CHILDREN 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int value;
} Child;

int main() {
    int N;
    
    while (scanf("%d", &N) && N != 0) {
        Child children[MAX_CHILDREN];
        for (int i = 0; i < N; i++) {
            scanf("%s %d", children[i].name, &children[i].value);
        }
        
        int index = 0;
        while (N > 1) {
            int count = children[index].value;
            int direction = (count % 2 == 0) ? 1 : -1;
            
            // Determine the index of the child to be eliminated
            int removeIndex = (index + direction * (count - 1) + N) % N;
            
            // Remove the child by shifting elements
            for (int i = removeIndex; i < N - 1; i++) {
                children[i] = children[i + 1];
            }
            
            N--; // Decrease the number of children
            index = removeIndex % N; // Update the index for next count
        }
        
        printf("Vencedor(a): %s\n", children[0].name);
    }
    
    return 0;
}
