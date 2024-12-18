#include <stdio.h>
#include <stdlib.h>

int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    *returnSize = pricesSize;
    int* result = (int*)malloc(pricesSize * sizeof(int));

    for (int i = 0; i < pricesSize; i++) {
        result[i] = prices[i];
        for (int j = i + 1; j < pricesSize; j++) {
            if (prices[j] <= prices[i]) {
                result[i] -= prices[j]; 
                break; 
            }
        }
    }

    return result;
}
// Test cases
int main() {
    // case 1
    int prices1[] = {8, 4, 6, 2, 3};
    int pricesSize1 = sizeof(prices1) / sizeof(prices1[0]);
    int returnSize1;
    int* result1 = finalPrices(prices1, pricesSize1, &returnSize1);
    
    printf("Output for prices1: ");
    for (int i = 0; i < returnSize1; i++) {
        printf("%d ", result1[i]);
    }
    printf("\n");
    free(result1);
    // case 2
    int prices2[] = {1, 2, 3, 4, 5};
    int pricesSize2 = sizeof(prices2) / sizeof(prices2[0]);
    int returnSize2;
    int* result2 = finalPrices(prices2, pricesSize2, &returnSize2);
    
    printf("Output for prices2: ");
    for (int i = 0; i < returnSize2; i++) {
        printf("%d ", result2[i]);
    }
    printf("\n");
    free(result2);
    // case 3
    int prices3[] = {10, 1, 1, 6};
    int pricesSize3 = sizeof(prices3) / sizeof(prices3[0]);
    int returnSize3;
    int* result3 = finalPrices(prices3, pricesSize3, &returnSize3);
    
    printf("Output for prices3: ");
    for (int i = 0; i < returnSize3; i++) {
        printf("%d ", result3[i]);
    }
    printf("\n");
    free(result3);

    return 0;
}
