#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int prefixCount(char** words, int wordsSize, char* pref) {
    int count = 0; 
    int prefLen = strlen(pref);

    for (int i = 0; i < wordsSize; i++) {
        if (strncmp(words[i], pref, prefLen) == 0) {
            count++; 
        }
    }

    return count;
}
// Test cases
int main() {
    // case 1
    char* words1[] = {"pay", "attention", "practice", "attend"};
    int size1 = sizeof(words1) / sizeof(words1[0]);
    char* pref1 = "at";
    printf("Output of case 1: %d\n", prefixCount(words1, size1, pref1)); // Expected answer: 2

    // case 2
    char* words2[] = {"leetcode", "win", "loops", "success"};
    int size2 = sizeof(words2) / sizeof(words2[0]);
    char* pref2 = "code";
    printf("Output of case 2: %d\n", prefixCount(words2, size2, pref2)); // Expected answer: 0

    return 0;
}
