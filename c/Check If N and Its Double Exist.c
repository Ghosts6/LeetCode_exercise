#include <stdio.h>
#include <stdbool.h>

bool checkIfExist(int* arr, int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        for (int j = 0; j < arrSize; j++) {
            if (i != j && arr[i] == 2 * arr[j]) {
                return true;
            }
        }
    }
    return false;
}
// Test cases
int main() {
    // case 1
    int arr1[] = {10, 2, 5, 3};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Test Case 1: %s\n", checkIfExist(arr1, size1) ? "true" : "false");
    
    // case 2
    int arr2[] = {3, 1, 7, 11};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Test Case 2: %s\n", checkIfExist(arr2, size2) ? "true" : "false");

    return 0;
}
