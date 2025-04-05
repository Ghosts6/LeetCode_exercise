#include <stdio.h>

int subsetXORSum(int* nums, int n) {
    int totalSum = 0;
    int subsetCount = 1 << n; 

    for (int i = 0; i < subsetCount; ++i) {
        int currentXOR = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) { 
                currentXOR ^= nums[j]; 
            }
        }
        totalSum += currentXOR;
    }

    return totalSum;
}
// Test cases
int main() {
    // case 1
    int nums1[] = {1, 3};
    int result1 = subsetXORSum(nums1, 2);
    printf("Output for nums = [1, 3]: %d\n", result1); // Expected output: 6
    
    // case 2
    int nums2[] = {5, 1, 6};
    int result2 = subsetXORSum(nums2, 3);
    printf("Output for nums = [5, 1, 6]: %d\n", result2); // Expected output: 28
    
    return 0;
}
