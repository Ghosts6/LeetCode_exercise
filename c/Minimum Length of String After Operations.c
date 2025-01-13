#include <stdio.h>
#include <string.h>

int minimumLength(char* s) {
    int n = strlen(s);
    int removableLen = 0;
    int freq[26] = {0};

    for (int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        int frequency = freq[i];
        if (frequency % 2 != 0) {
            removableLen += frequency - 1;
        } else if (frequency != 0) {
            removableLen += frequency - 2;
        }
    }

    return n - removableLen;
}

// Test cases
int main() {
    // case 1
    char* s1 = "abaacbcbb";
    printf("Input: %s - Output: %d\n", s1, minimumLength(s1)); // Expected Output: 5
    // case 2
    char* s2 = "aa";
    printf("Input: %s - Output: %d\n", s2, minimumLength(s2)); // Expected Output: 2
    // edge case
    char* s3 = "vbllfac";
    printf("Input: %s - Output: %d\n", s3, minimumLength(s3)); // Expected Output: 7

    return 0;
}