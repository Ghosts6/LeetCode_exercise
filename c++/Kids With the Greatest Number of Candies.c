#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    int maxCandies = 0;
    for (int i = 0; i < candiesSize; i++) {
        if (candies[i] > maxCandies) {
            maxCandies = candies[i];
        }
    }

    bool* result = (bool*)malloc(candiesSize * sizeof(bool));
    if (!result) {
        *returnSize = 0;
        return NULL;
    }

    for (int i = 0; i < candiesSize; i++) {
        result[i] = (candies[i] + extraCandies >= maxCandies);
    }

    *returnSize = candiesSize;
    return result;
}
//  test case
int main() {
    int candies[] = {2, 3, 5, 1, 3};
    int extraCandies = 3;
    int candiesSize = sizeof(candies) / sizeof(candies[0]);
    int returnSize;

    bool* result = kidsWithCandies(candies, candiesSize, extraCandies, &returnSize);

    printf("Result: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%s ", result[i] ? "true" : "false");
    }

    printf("\n");
    free(result);
    return 0;
}
