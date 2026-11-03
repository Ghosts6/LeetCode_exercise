#include <stdio.h>

int minMoves(int* nums, int numsSize) {	
    int max = nums[0];
    int result = 0;

    for(int i = 1; i < numsSize; i++) {
        if (nums[i] > max) {
	    max = nums[i];
	}
    }

    for(int i = 0; i < numsSize; i++) {
        if (nums[i] < max) {
            result += (max - nums[i]);
        }
    }

    return result;
}

// Test cases
int main() {
    // case 1
    int nums1[] = {2, 1, 3};
    int numsSize1 = 3;
    printf("Result of test case 1 : %d\n", minMoves(nums1, numsSize1)); // Expected: 3

    // case 2
    int nums2[] = {4, 4, 5};
    int numsSize2 = 3;
    printf("Result of test case 2 : %d\n", minMoves(nums2, numsSize2)); // Expected: 2

    return 0;
}
