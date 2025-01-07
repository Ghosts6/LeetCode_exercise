#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* minOperations(char* boxes, int* returnSize) {
    int n = strlen(boxes);  
    *returnSize = n; 

    int* result = (int*)malloc(n * sizeof(int));
    memset(result, 0, n * sizeof(int));

    int moves = 0, count = 0;
    for (int i = 0; i < n; ++i) {
        result[i] += moves;
        count += boxes[i] == '1' ? 1 : 0;
        moves += count;
    }

    moves = 0;
    count = 0;
    for (int i = n - 1; i >= 0; --i) {
        result[i] += moves;
        count += boxes[i] == '1' ? 1 : 0;
        moves += count;
    }

    return result;
}
// Test cases
int main() {
    // case 1
    char* boxes1 = "110";
    int returnSize1 = 0;
    int* result1 = minOperations(boxes1, &returnSize1);
    printf("Test case 1: ");
    for (int i = 0; i < returnSize1; i++) {
        printf("%d ", result1[i]); // Expected Output: 1,1,3
    }
    printf("\n");
    free(result1);

    // case 2
    char* boxes2 = "001011";
    int returnSize2 = 0;
    int* result2 = minOperations(boxes2, &returnSize2);
    printf("Test case 2: ");
    for (int i = 0; i < returnSize2; i++) {
        printf("%d ", result2[i]); // Expected Output: 11,8,5,4,3,4
    }
    printf("\n");
    free(result2);

    return 0;
}