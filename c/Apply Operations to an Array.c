#include <stdio.h>
#include <stdlib.h>

int* applyOperations(int* nums, int numSize, int* returnSize) {
    for (int i = 0; i < numSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            nums[i] *= 2;
            nums[i + 1] = 0;
        }
    }

    int* result = (int*)malloc(numSize * sizeof(int));
    int index = 0;

    for (int i = 0; i < numSize; i++) {
        if (nums[i] != 0) {
            result[index++] = nums[i];
        }
    }

    while (index < numSize) {
        result[index++] = 0;
    }

    *returnSize = numSize;
    return result;
}

// Test case
int main() {
    // Case 1
    int nums1[] = {1, 2, 2, 1, 1, 0};
    int numSize1 = 6;
    int returnSize1;
    int* result1 = applyOperations(nums1, numSize1, &returnSize1);

    printf("Result of test case 1: ");
    for (int i = 0; i < returnSize1; i++) {
        printf("%d ", result1[i]); // Expected output: 1,4,2,0,0,0
    }
    printf("\n");
    free(result1);

    // Case 2
    int nums2[] = {0, 1};
    int numSize2 = 2;
    int returnSize2;
    int* result2 = applyOperations(nums2, numSize2, &returnSize2);

    printf("Result of test case 2: ");
    for (int i = 0; i < returnSize2; i++) {
        printf("%d ", result2[i]); // Expected output: 1,0
    }
    printf("\n");
    free(result2);

    return 0;
}
