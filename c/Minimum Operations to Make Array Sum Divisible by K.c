#include <stdio.h>
#include <stdlib.h>

int minOperations(int* nums, int numsSize, int k);

// Test cases
int main() {
	// case 1
	int nums1[] = {3, 9, 7};
	int k1 = 5;
	printf("Result of test case 1 : %d\n", minOperations(nums1, 3, k1)); // Expected: 4
	
	// case 2
	int nums2[] = {4, 1, 3};
	int k2 = 4;
	printf("Result of test case 2 : %d\n", minOperations(nums2, 3, k2)); // Expected: 0
	
	// case 3
	int nums3[] = {3, 2};
	int k3 = 6;
	printf("Result of test case 3 : %d\n", minOperations(nums3, 2, k3)); // Expected: 5
	
	return 0;
}

int minOperations(int* nums, int n, int k) {
    long long sum = 0;
    for (int i = 0; i < n; i++) sum += nums[i];
    return sum % k;
}

