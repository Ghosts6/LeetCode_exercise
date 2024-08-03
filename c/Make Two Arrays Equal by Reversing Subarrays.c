#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool canBeEqual(int* target, int targetSize, int* arr, int arrSize) {
    if (targetSize != arrSize) {
        return false;
    }

    int* count = (int*)calloc(1001, sizeof(int)); 

    for (int i = 0; i < targetSize; i++) {
        count[target[i]]++;
        count[arr[i]]--;
    }

    for (int i = 0; i < 1001; i++) {
        if (count[i] != 0) {
            free(count);
            return false;
        }
    }

    free(count);
    return true;
}
//  test case
int main() {
    int target1[] = {1, 2, 3, 4};
    int arr1[] = {2, 4, 1, 3};
    int target2[] = {1, 2, 3, 4};
    int arr2[] = {1, 2, 3, 5};
    int targetSize1 = sizeof(target1) / sizeof(target1[0]);
    int arrSize1 = sizeof(arr1) / sizeof(arr1[0]);
    int targetSize2 = sizeof(target2) / sizeof(target2[0]);
    int arrSize2 = sizeof(arr2) / sizeof(arr2[0]);
    // success case
    if (canBeEqual(target1, targetSize1, arr1, arrSize1)) {
        printf("Test case 1 passed.\n");
    } else {
        printf("Test case 1 failed.\n");
    }
    // failure case
    if (canBeEqual(target2, targetSize2, arr2, arrSize2)) {
        printf("Test case 2 failed.\n");
    } else {
        printf("Test case 2 passed.\n");
    }

    return 0;
}
