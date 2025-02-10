#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 50
#define MAX_WORD_LENGTH 21

int is_tautogram(char *sentence) {
    char *word;
    char first_letter = '\0';
    
    // Tokenize the sentence using space as delimiter
    word = strtok(sentence, " ");
    while (word != NULL) {
        // Extract the first letter and convert to lowercase
        char current_first_letter = tolower(word[0]);
        
        // If this is the first word, initialize the first_letter
        if (first_letter == '\0') {
            first_letter = current_first_letter;
        }
        
        // Compare with the initial letter
        if (current_first_letter != first_letter) {
            return 0; // Not a tautogram
        }
        
        word = strtok(NULL, " ");
    }
    
    return 1; // All words start with the same letter
}

int main() {
    char line[1000];

    while (fgets(line, sizeof(line), stdin)) {
        // Remove trailing newline character
        line[strcspn(line, "\n")] = 0;
        
        if (strcmp(line, "*") == 0) {
            break;
        }
        
        if (is_tautogram(line)) {
            printf("Y\n");
        } else {
            printf("N\n");
        }
    }

    return 0;
}
