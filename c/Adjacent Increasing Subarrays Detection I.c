#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool hasIncreasingSubarrays(int* nums, int numsSize, int k);

int main() {
	// case 1
	int nums[] = {2, 5, 7, 8, 9, 2, 3, 4, 3, 1};
	int numsSize = 10, k = 3;
	printf("Result of test case 1 : %d\n", hasIncreasingSubarrays(nums, numsSize, k)); // Expected true

	// case 2
	int nums2[] = {1, 2, 3, 4, 4, 4, 4, 5, 6, 7};
	int numsSize2 = 10, k2 = 5;
	printf("Result of test case 2 : %d\n", hasIncreasingSubarrays(nums2, numsSize2, k2)); // Expected false

	return 0;
}

bool hasIncreasingSubarrays(int* nums, int numsSize, int k) {
    if (numsSize < 2 * k) return false; // not enough elementsi

    int firstEnd = -1;
    int count = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i - 1]) count++;
        else count = 1;

        if (count >= k) {
            if (firstEnd == -1) {
                firstEnd = i;             
	    } else if (i - firstEnd >= k) {
                return true; 
	    }
        }
    }

    return false;
}
