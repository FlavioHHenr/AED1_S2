#include <stdio.h>
#include <stdlib.h>

#define MAX 2000

typedef struct {
    int number;
    int count;
} Element;

int compare(const void *a, const void *b) {
    return ((Element *)a)->number - ((Element *)b)->number;
}

int main() {
    int N;
    scanf("%d", &N);

    if (N < 1 || N > MAX) {
        return 1; // erro se N estiver fora dos limites
    }

    Element elements[MAX];
    int index = 0;
    int num;
    int found;
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        
        found = 0;
        for (int j = 0; j < index; j++) {
            if (elements[j].number == num) {
                elements[j].count++;
                found = 1;
                break;
            }
        }
        
        if (!found) {
            elements[index].number = num;
            elements[index].count = 1;
            index++;
        }
    }
    
    qsort(elements, index, sizeof(Element), compare);
    
    for (int i = 0; i < index; i++) {
        printf("%d aparece %d vez(es)\n", elements[i].number, elements[i].count);
    }
    
    return 0;
}
