#include <stdio.h>
#include <string.h>

// Marco
#define MIN(a, b) ((a) < (b) ? (a) : (b))

// Prototype
int minOperations(char* s);

// Test case 
int main() {
    // case 1
    char s1[] = "0100";
    printf("Result of test case 1: %d\n", minOperations(s1)); // Expetced: 1

    // case 2
    char s2[] = "10";
    printf("Result of test case 2: %d\n", minOperations(s2)); // Expected: 0

    // case 3
    char s3[] = "1111";
    printf("Result of test case 3: %d\n", minOperations(s3)); // Expected: 2

    return 0;
}

int minOperations(char* s) {
    int n = strlen(s);
    int count0 = 0;

    for (int i = 0; i < n; i++) {
        char expected = (i % 2 == 0) ? '0' : '1';
        
        if (s[i] != expected) {
            count0++;
        }
    }

    return MIN(count0, n - count0);
}
