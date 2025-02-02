#include <stdbool.h>
#include <stdio.h>

bool check(int* nums, int numsSize) {
    int count = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > nums[(i + 1) % numsSize]) {
            count++;
        }
    }

    return count <= 1;   
}
// Test cases
int main() {
    // case 1
    int nums1[] = {3, 4, 5, 1, 2};
    printf("%s\n", check(nums1, 5) ? "true" : "false"); // Expected Output: true

    // case 2
    int nums2[] = {2, 1, 3, 4};
    printf("%s\n", check(nums2, 4) ? "true" : "false"); // Expected Output: false

    // case 3
    int nums3[] = {1, 2, 3};
    printf("%s\n", check(nums3, 3) ? "true" : "false"); // Expected Output: true

    return 0;
}