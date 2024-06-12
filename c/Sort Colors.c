#include <stdio.h>

void sortColors(int* nums, int numsSize) {
    int red = 0, white = 0, blue = numsSize - 1;
    
    while (white <= blue) {
        if (nums[white] == 0) {
            int temp = nums[white];
            nums[white] = nums[red];
            nums[red] = temp;
            red++;
            white++;
        } else if (nums[white] == 1) {
            white++;
        } else {
            int temp = nums[white];
            nums[white] = nums[blue];
            nums[blue] = temp;
            blue--;
        }
    }
}

// test cases
int main() {
    int nums[] = {2, 0, 2, 1, 1, 0};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    
    sortColors(nums, numsSize);
    
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    
    return 0;
}
