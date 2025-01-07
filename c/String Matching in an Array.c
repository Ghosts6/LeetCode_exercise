#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isSubstring(char* sub, char* str) {
    return strstr(str, sub) != NULL;
}

char** stringMatching(char** words, int wordSize, int* returnSize) {
    char** result = (char**)malloc(wordSize * sizeof(char*));
    *returnSize = 0; 

    for (int i = 0; i < wordSize; i++) {
        for (int j = 0; j < wordSize; j++) {
            if (i != j && isSubstring(words[i], words[j])) {
                result[*returnSize] = words[i];  
                (*returnSize)++; 
                break;
            }
        }
    }
    return result; 
}
// Test cases
int main() {
    // case 1
    char* words1[] = {"mass", "as", "hero", "superhero"};
    int wordSize1 = 4;
    int returnSize1 = 0;
    char** result1 = stringMatching(words1, wordSize1, &returnSize1);
    printf("Test case 1: ");
    for (int i = 0; i < returnSize1; i++) {
        printf("\"%s\" ", result1[i]);
    }
    printf("\n");
    
    // case 2
    char* words2[] = {"leetcode", "et", "code"};
    int wordSize2 = 3;
    int returnSize2 = 0;
    char** result2 = stringMatching(words2, wordSize2, &returnSize2);
    printf("Test case 2: ");
    for (int i = 0; i < returnSize2; i++) {
        printf("\"%s\" ", result2[i]);
    }
    printf("\n");
    
    // case 3
    char* words3[] = {"blue", "green", "bu"};
    int wordSize3 = 3;
    int returnSize3 = 0;
    char** result3 = stringMatching(words3, wordSize3, &returnSize3);
    printf("Test case 3: ");
    for (int i = 0; i < returnSize3; i++) {
        printf("\"%s\" ", result3[i]);
    }
    printf("\n");

    // Free memory
    free(result1);
    free(result2);
    free(result3);
    
    return 0;
}