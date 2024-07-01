#include <stdio.h>
#include <stdbool.h>

bool threeConsecutiveOdds(int* arr, int arrSize) {
    for (int i = 0; i < arrSize - 2; ++i) {
        if (arr[i] % 2 != 0 && arr[i + 1] % 2 != 0 && arr[i + 2] % 2 != 0) {
            return true;
        }
    }
    return false;
}
//  test case
int main() {
    int arr1[] = {2, 6, 4, 1};
    int arrSize1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Test case 1: %s\n", threeConsecutiveOdds(arr1, arrSize1) ? "true" : "false"); 

    int arr2[] = {1, 3, 5, 7, 9};
    int arrSize2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Test case 2: %s\n", threeConsecutiveOdds(arr2, arrSize2) ? "true" : "false"); 

    return 0;
}
