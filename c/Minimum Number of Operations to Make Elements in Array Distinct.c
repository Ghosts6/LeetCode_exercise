#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int minimumOperations(int* nums, int numsSize) {
    bool freq[101] = {};
    for (int i = numsSize - 1; i >= 0; i--) {
        if (freq[nums[i]])
            return ceil((double) (i + 1) / 3);
        freq[nums[i]] = true;
    }
    return 0;
}

// Test case
int main() {
    // case 1
    int nums1[] = {1,2,3,4,2,3,3,5,7};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Result of test case 1 : %d \n", minimumOperations(nums1, numsSize1)); // Expected Output: 2

    // case 2
    int nums2[] = {4,5,6,4,4};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Result of test case 2 : %d \n", minimumOperations(nums2, numsSize2)); // Expected Output: 2

    // case 3
    int nums3[] = {6,7,8,9};
    int numsSize3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Result of test case 3 : %d \n", minimumOperations(nums3, numsSize3)); // Expected Output: 0

    return 0;
}