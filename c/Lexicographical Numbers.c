#include <stdio.h>
#include <stdlib.h>

int* lexicalOrder(int n, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * n);
    int index = 0;
    int current = 1;

    while (index < n) {
        result[index++] = current;
        
        if (current * 10 <= n) {
            current *= 10;
        } else {
            while (current % 10 == 9 || current + 1 > n) {
                current /= 10;
            }
            current++;
        }
    }

    *returnSize = n;
    return result;
}

// Test cases && helper function
void printLexicalOrder(int n) {
    int returnSize;
    int* result = lexicalOrder(n, &returnSize);

    printf("Lexicographical order for n = %d: ", n);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
}

int main() {
    // Case 1
    printLexicalOrder(13); // Expected output: 1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9

    // Case 2
    printLexicalOrder(2); // Expected output: 1, 2

    return 0;
}

