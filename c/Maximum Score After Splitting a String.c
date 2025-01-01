#include <stdio.h>
#include <string.h>

int maxScore(char* s) {
    int n = strlen(s);
    int totalOnes = 0, leftZeros = 0, maxScore = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            totalOnes++;
        }
    }

    int rightOnes = totalOnes;

    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '0') {
            leftZeros++;
        } else if (s[i] == '1') {
            rightOnes--;
        }

        int score = leftZeros + rightOnes;
        if (score > maxScore) {
            maxScore = score;
        }
    }

    return maxScore;
}
// Test cases
int main () {
    // case 1
    char s1[] = "011101";
    printf("Input: s = \"%s\"\nOutput: %d\n", s1, maxScore(s1)); // Output: 5
    // case 2
    char s2[] = "00111";
    printf("Input: s = \"%s\"\nOutput: %d\n", s2, maxScore(s2)); // Output: 5
    // case 3
    char s3[] = "1111";
    printf("Input: s = \"%s\"\nOutput: %d\n", s3, maxScore(s3)); // Output: 3
}