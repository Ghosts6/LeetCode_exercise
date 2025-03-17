#include <stdio.h>
#include <stdbool.h>

bool divideArray(int* nums, int numsSize) {
    if (numsSize % 2 != 0) return false;

    int freq[100001] = {0};
    for (int i = 0; i < numsSize; i++) {
        freq[nums[i]]++;
    }

    for (int i = 0; i < 100001; i++) {
        if (freq[i] % 2 != 0) return false;
    }

    return true;
}
// Test cases
int main() {
    // case 1
    int nums1[] = {3, 2, 3, 2, 2, 2};
    printf("%s\n", divideArray(nums1, 6) ? "true" : "false"); // true

    // case 2
    int nums2[] = {1, 2, 3, 4};
    printf("%s\n", divideArray(nums2, 4) ? "true" : "false"); // false

    return 0;
}
