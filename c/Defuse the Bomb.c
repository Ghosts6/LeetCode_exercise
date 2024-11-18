#include <stdio.h>

int* decrypt(int* code, int codeSize, int k, int* returnSize) {
    *returnSize = codeSize;
    int* result = (int*)malloc(codeSize * sizeof(int));

    if (k == 0) {
        for (int i = 0; i < codeSize; i++) {
            result[i] = 0;
        }
        return result;
    }

    for (int i = 0; i < codeSize; i++) {
        int sum = 0;

        if (k > 0) {
            for (int j = 1; j <= k; j++) {
                sum += code[(i + j) % codeSize];
            }
        }

        else if (k < 0) {
            for (int j = 1; j <= -k; j++) {
                sum += code[(i - j + codeSize) % codeSize];
            }
        }

        result[i] = sum;
    }

    return result;
}

// Test case
int main() {
    int code[] = {5, 7, 1, 4};
    int codeSize = 4;
    int k = 3;
    int returnSize;
    
    int* decryptedCode = decrypt(code, codeSize, k, &returnSize);
    
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", decryptedCode[i]);
    }
    printf("\n");

    free(decryptedCode);

    return 0;
}
