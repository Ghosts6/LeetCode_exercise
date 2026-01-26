#include <stdio.h>
#include <stdlib.h>

// Prototype
int cmp(const void* a, const void* b);
int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes);

// Helper method
void printResult(int testCase, int** res, int returnSize) {
    printf("Result of test case %d:\n", testCase);
    for (int i = 0; i < returnSize; i++) {
        printf("  [%d, %d]\n", res[i][0], res[i][1]);
    }
}

// Test cases
int main() {
    int returnSize;
    int* returnColumnSizes;

    // case 1
    int arr1[] = {4, 2, 1, 3};
    int size1 = 4;
    int** res1 = minimumAbsDifference(arr1, size1, &returnSize, &returnColumnSizes);
    printResult(1, res1, returnSize);
    for (int i = 0; i < returnSize; i++) free(res1[i]);
    free(res1);
    free(returnColumnSizes);

    // case 2
    int arr2[] = {1, 3, 6, 10, 15};
    int size2 = 5;
    int** res2 = minimumAbsDifference(arr2, size2, &returnSize, &returnColumnSizes);
    printResult(2, res2, returnSize);
    for (int i = 0; i < returnSize; i++) free(res2[i]);
    free(res2);
    free(returnColumnSizes);

    // case 3
    int arr3[] = {3, 8, -10, 23, 19, -4, -14, 27};
    int size3 = 8;
    int** res3 = minimumAbsDifference(arr3, size3, &returnSize, &returnColumnSizes);
    printResult(3, res3, returnSize);
    for (int i = 0; i < returnSize; i++) free(res3[i]);
    free(res3);
    free(returnColumnSizes);

    return 0;
}

// Solution
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes) {
    qsort(arr, arrSize, sizeof(int), cmp);

    int minDiff = abs(arr[1] - arr[0]);
    for (int i = 2; i < arrSize; i++) {
        int diff = arr[i] - arr[i - 1];
        if (diff < minDiff) minDiff = diff;
    }

    int count = 0;
    for (int i = 1; i < arrSize; i++) {
        if (arr[i] - arr[i - 1] == minDiff) count++;
    }

    int** result = (int**)malloc(count * sizeof(int*));
    *returnColumnSizes = (int*)malloc(count * sizeof(int));
    *returnSize = count;

    int idx = 0;
    for (int i = 1; i < arrSize; i++) {
        if (arr[i] - arr[i - 1] == minDiff) {
            result[idx] = (int*)malloc(2 * sizeof(int));
            result[idx][0] = arr[i - 1];
            result[idx][1] = arr[i];
            (*returnColumnSizes)[idx] = 2;
            idx++;
        }
    }

    return result;
}
