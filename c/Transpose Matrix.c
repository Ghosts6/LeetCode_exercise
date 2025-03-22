#include <stdio.h>
#include <stdlib.h>

int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = *matrixColSize;
    *returnColumnSizes = (int*)malloc(*returnSize * sizeof(int));

    int** result = (int**)malloc(*returnSize * sizeof(int*));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = matrixSize;
        result[i] = (int*)malloc(matrixSize * sizeof(int));
        for (int j = 0; j < matrixSize; j++) {
            result[i][j] = matrix[j][i];
        }
    }
    return result;
}

void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void printMatrix(int** matrix, int rows, int* cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols[i]; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
// Test cases
int main() {
    // case 1
    int matrix1[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rows1 = 3, cols1 = 3;
    int* mat1[3] = {matrix1[0], matrix1[1], matrix1[2]};
    
    int returnSize, *returnColumnSizes;
    int** result1 = transpose(mat1, rows1, &cols1, &returnSize, &returnColumnSizes);
    printf("case 1:\n");
    printMatrix(result1, returnSize, returnColumnSizes);
    freeMatrix(result1, returnSize);
    free(returnColumnSizes);
    // case 2
    int matrix2[][3] = {{1, 2, 3}, {4, 5, 6}};
    int rows2 = 2, cols2 = 3;
    int* mat2[2] = {matrix2[0], matrix2[1]};

    int** result2 = transpose(mat2, rows2, &cols2, &returnSize, &returnColumnSizes);
    printf("case 2:\n");
    printMatrix(result2, returnSize, returnColumnSizes);
    freeMatrix(result2, returnSize);
    free(returnColumnSizes);

    return 0;
}
