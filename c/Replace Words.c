#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Helper function to check if a word starts with a root
bool startsWith(const char *word, const char *root) {
    while (*root) {
        if (*word++ != *root++) {
            return false;
        }
    }
    return true;
}

// Function to replace derivatives with roots in the sentence
char* replaceWords(char **roots, int rootsSize, char *sentence) {
    char *result = malloc(strlen(sentence) + 1);
    char *token = strtok(sentence, " ");
    bool firstWord = true;

    result[0] = '\0';

    while (token != NULL) {
        char *replacement = token;
        int minLen = strlen(token);

        for (int i = 0; i < rootsSize; ++i) {
            if (startsWith(token, roots[i])) {
                int rootLen = strlen(roots[i]);
                if (rootLen < minLen) {
                    replacement = roots[i];
                    minLen = rootLen;
                }
            }
        }

        if (firstWord) {
            firstWord = false;
        } else {
            strcat(result, " ");
        }
        strcat(result, replacement);

        token = strtok(NULL, " ");
    }

    return result;
}
//  test case
int main() {
    char *roots[] = {"cat", "bat", "rat"};
    char sentence[] = "the cattle was rattled by the battery";
    char *result1 = replaceWords(roots, 3, sentence);

    printf("Result 1: %s\n", result1);

    free(result1);

    testReplaceWords();
    
    return 0;
}
