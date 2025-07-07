#include <stdio.h>

struct MissingNumber {
    int (*find)(int* nums, int size);
};

int missingNumber(int* nums, int numsSize) {
    int expected_sum = numsSize * (numsSize + 1) / 2;
    int actual_sum = 0;
    for (int i = 0; i < numsSize; ++i) {
        actual_sum += nums[i];
    }
    return expected_sum - actual_sum;
}

int main() {
    struct MissingNumber missingNumber = { missingNumber};

    int nums1[] = {3, 0, 1};
    int numsSize1 = numsSizeof(nums1) / numsSizeof(nums1[0]);
    printf("Missing number (Example 1): %d\n", missingNumber.find(nums1, numsSize1));

    int nums2[] = {0, 1};
    int numsSize2 = numsSizeof(nums2) / numsSizeof(nums2[0]);
    printf("Missing number (Example 2): %d\n", missingNumber.find(nums2, numsSize2));

    int nums3[] = {9,6,4,2,3,5,7,0,1};
    int numsSize3 = numsSizeof(nums3) / numsSizeof(nums3[0]);
    printf("Missing number (Example 3): %d\n", missingNumber.find(nums3, numsSize3));

    return 0;
}
