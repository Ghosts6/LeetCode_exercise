#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPrefix(const char* word, const char* searchWord) {
    while (*searchWord && *word == *searchWord) {
        word++;
        searchWord++;
    }
    return *searchWord == '\0';
}

int isPrefixOfWord(const char* sentence, const char* searchWord) {
    int wordIndex = 1;
    const char* wordStart = sentence;
    
    while (*sentence) {
        if (*sentence == ' ' || *sentence == '\0') {
            int wordLength = sentence - wordStart;
            char currentWord[wordLength + 1];
            strncpy(currentWord, wordStart, wordLength);
            currentWord[wordLength] = '\0';
            
            if (isPrefix(currentWord, searchWord)) {
                return wordIndex;
            }
            
            wordIndex++;
            wordStart = sentence + 1;
        }
        sentence++;
    }
    
    if (isPrefix(wordStart, searchWord)) {
        return wordIndex;
    }

    return -1;
}
// Test cases
int main() {
    printf("Test 1: %d\n", isPrefixOfWord("i love eating burger", "burg")); // Output: 4
    printf("Test 2: %d\n", isPrefixOfWord("this problem is an easy problem", "pro")); // Output: 2
    printf("Test 3: %d\n", isPrefixOfWord("i am tired", "you")); // Output: -1

    return 0;
}