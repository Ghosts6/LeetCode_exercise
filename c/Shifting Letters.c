#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* shiftingLetters(char* s, int* shifts, int shiftsSize) {
    int n = strlen(s);
    long long totalShift = 0;

    char* result = (char*)malloc((n + 1) * sizeof(char));
    if (!result) return NULL;  

    for (int i = n - 1; i >= 0; --i) {
        totalShift = (totalShift + shifts[i]) % 26;
        result[i] = ((s[i] - 'a' + totalShift) % 26) + 'a';
    }

    result[n] = '\0';
    return result;
}

// Test cases
int main() {
    // Test case 1
    char s1[] = "abc";
    int shift1[] = {3, 5, 9};
    char* result1 = shiftingLetters(s1, shift1, 3);
    if (result1) {
        printf("%s\n", result1);  // Expected: rpl
        free(result1);
    }

    // Test case 2
    char s2[] = "aaa";
    int shift2[] = {1, 2, 3};
    char* result2 = shiftingLetters(s2, shift2, 3);
    if (result2) {
        printf("%s\n", result2);  // Expected: gfd
        free(result2);
    }

    return 0;
}

