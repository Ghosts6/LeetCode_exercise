#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int specialArray(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    for (int x = 0; x <= numsSize; x++) {
        int count = 0;
        for (int i = 0; i < numsSize; i++) {
            if (nums[i] >= x) {
                count = numsSize - i; 
                break;
            }
        }

        if (count == x) {
            return x;
        }
    }
    return -1;
}
//  test case
int main() {
    int nums1[] = {3, 5, 2, 7, 3};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("special value for nums1: %d\n", specialArray(nums1, numsSize1)); 

    int nums2[] = {0, 4, 3, 0, 4};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("special value for nums2: %d\n", specialArray(nums2, numsSize2));

    return 0;
}
