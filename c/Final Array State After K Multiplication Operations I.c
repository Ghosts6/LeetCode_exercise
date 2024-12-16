#include <stdio.h>

int* getFinalState(int* nums, int numsSize, int k, int multiplier, int* returnSize) {
    *returnSize = numsSize; 
    
    for (int op = 0; op < k; op++) {
        int minIndex = 0;
        for (int i = 1; i < numsSize; i++) {
            if (nums[i] < nums[minIndex]) {
                minIndex = i;
            }
        }
        nums[minIndex] *= multiplier;
    }
  
    return nums; 
}
//  Test case
int main() {
    // case 1
    int nums1[] = {2, 1, 3, 5, 6};
    int numsSize1 = 5;
    int k1 = 5;
    int multiplier1 = 2;
    int returnSize1;
    int* result1 = getFinalState(nums1, numsSize1, k1, multiplier1, &returnSize1);
    printf("Output: ");
    for (int i = 0; i < returnSize1; i++) {
        printf("%d ", result1[i]);
    }
    printf("\n");
    
    // case 2
    int nums2[] = {1, 2};
    int numsSize2 = 2;
    int k2 = 3;
    int multiplier2 = 4;
    int returnSize2;
    int* result2 = getFinalState(nums2, numsSize2, k2, multiplier2, &returnSize2);
    printf("Output: ");
    for (int i = 0; i < returnSize2; i++) {
        printf("%d ", result2[i]);
    }
    printf("\n");
    
    return 0;
}
