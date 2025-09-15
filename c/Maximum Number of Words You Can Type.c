#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int canBeTypedWords(char *text, char *brokenLetters) {
    bool broken[26] = {false};

    // Mark broken letters
    for (int i = 0; brokenLetters[i]; i++) {
        broken[brokenLetters[i] - 'a'] = true;
    }

    int count = 0;
    bool valid = true;

    for (int i = 0; ; i++) {
        char c = text[i];

        if (c == ' ' || c == '\0') {
            if (valid) count++;   // Word was valid
            valid = true;         // Reset for next word
            if (c == '\0') break; // End of string
        } else {
            if (broken[c - 'a']) valid = false; // Word is invalid
        }
    }

    return count;
}
// Test cases
int main() {
    // case 1
    char text1[] = "hello world";
    char broken1[] = "ad";
    printf("Result of test case 1 : %d\n", canBeTypedWords(text1, broken1)); // Expected 1

    // Example 2
    char text2[] = "leet code";
    char broken2[] = "lt";
    printf("Result of test case %d\n", canBeTypedWords(text2, broken2)); // Expected 1

    // Example 3
    char text3[] = "leet code";
    char broken3[] = "e";
    printf("Result of test case 3 : %d\n", canBeTypedWords(text3, broken3)); // Expected 0

    return 0;
}
