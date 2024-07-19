#include <stdlib.h>

int* luckyNumbers(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int* result = (int*)malloc(matrixSize * sizeof(int)); 
    int resultCount = 0; 

    for (int i = 0; i < matrixSize; ++i) {
        int minRowValue = matrix[i][0];
        int minRowIndex = 0;
        for (int j = 1; j < matrixColSize[i]; ++j) {
            if (matrix[i][j] < minRowValue) {
                minRowValue = matrix[i][j];
                minRowIndex = j;
            }
        }

        int isLucky = 1; 
        for (int k = 0; k < matrixSize; ++k) {
            if (matrix[k][minRowIndex] > minRowValue) {
                isLucky = 0;
                break;
            }
        }

        if (isLucky) {
            result[resultCount++] = minRowValue;
        }
    }

    *returnSize = resultCount; 
    return result; 
}
//  test case 
int main() {
    int matrixSize = 3;
    int matrixColSize[] = {3, 3, 3};

    int** matrix = (int**)malloc(matrixSize * sizeof(int*));
    matrix[0] = (int[]) {3, 7, 8};
    matrix[1] = (int[]) {9, 11, 13};
    matrix[2] = (int[]) {15, 16, 17};

    int returnSize;
    int* luckyNums = luckyNumbers(matrix, matrixSize, matrixColSize, &returnSize);

    printf("Lucky Numbers: ");
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", luckyNums[i]);
    }
    printf("\n");

    free(luckyNums);
    free(matrix);

    return 0;
}