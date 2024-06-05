#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

char** commonChars(char** words, int wordsSize, int* returnSize) {
    char** result = (char**)malloc(100 * sizeof(char*));
    int k = 0;

    for (char c = 'a'; c <= 'z'; ++c) {
        int min_count = INT_MAX;
        
        for (int i = 0; i < wordsSize; ++i) {
            int count = 0;
            int wordLen = strlen(words[i]);
            for (int j = 0; j < wordLen; ++j) {
                if (words[i][j] == c) {
                    count++;
                }
            }
            if (count < min_count) {
                min_count = count;
            }
            if (min_count == 0) {
                break;
            }
        }

        for (int i = 0; i < min_count; ++i) {
            result[k] = (char*)malloc(2 * sizeof(char));
            result[k][0] = c;
            result[k][1] = '\0';
            k++;
        }
    }

    *returnSize = k;
    return result;
}

// test case
int main() {
    char* words[] = {"bella", "label", "roller"};
    int wordsSize = 3;
    int returnSize;
    char** result = commonChars(words, wordsSize, &returnSize);

    for (int i = 0; i < returnSize; ++i) {
        printf("%s\n", result[i]);
        free(result[i]);
    }
    free(result);

    return 0;
}
