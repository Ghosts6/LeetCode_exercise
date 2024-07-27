#include <stdlib.h>
#include <string.h>

typedef struct {
    int original;
    int mapped;
    int index; 
} MappedNumber;

int mapValue(int num, int* mapping) {
    if (num == 0) {
        return mapping[0];
    }

    int mappedValue = 0;
    int place = 1;

    while (num > 0) {
        int digit = num % 10;
        mappedValue = mappedValue + mapping[digit] * place;
        num /= 10;
        place *= 10;
    }

    return mappedValue;
}

int compare(const void* a, const void* b) {
    MappedNumber* num1 = (MappedNumber*)a;
    MappedNumber* num2 = (MappedNumber*)b;

    if (num1->mapped == num2->mapped) {
        return num1->index - num2->index;
    }

    return num1->mapped - num2->mapped;
}

int* sortJumbled(int* mapping, int mappingSize, int* nums, int numsSize, int* returnSize) {
    MappedNumber* mappedNumbers = (MappedNumber*)malloc(numsSize * sizeof(MappedNumber));
    for (int i = 0; i < numsSize; ++i) {
        mappedNumbers[i].original = nums[i];
        mappedNumbers[i].mapped = mapValue(nums[i], mapping);
        mappedNumbers[i].index = i;
    }

    qsort(mappedNumbers, numsSize, sizeof(MappedNumber), compare);

    int* sortedNums = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; ++i) {
        sortedNums[i] = mappedNumbers[i].original;
    }

    free(mappedNumbers);

    *returnSize = numsSize;
    return sortedNums;
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
//  test case
int main() {
    int mapping[] = {2, 1, 4, 8, 6, 3, 0, 9, 7, 5};
    int nums[] = {990, 332, 981};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int* sortedNums = sortJumbled(mapping, 10, nums, numsSize, &returnSize);

    printArray(sortedNums, returnSize);  

    free(sortedNums);
    return 0;
}
