#include <stdio.h>
#include <stdlib.h>

int countSquares(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize, n = matrixColSize[0], count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1 && i > 0 && j > 0) {
                int min = matrix[i-1][j];
                if (matrix[i][j-1] < min) min = matrix[i][j-1];
                if (matrix[i-1][j-1] < min) min = matrix[i-1][j-1];
                matrix[i][j] = min + 1;
            }
            count += matrix[i][j];
        }
    }
    return count;
}

int main() {
    int m1[3][4] = {
        {0,1,1,1},
        {1,1,1,1},
        {0,1,1,1}
    };
    int* matrix1[3] = {m1[0], m1[1], m1[2]};
    int colSize1[1] = {4};
    printf("Output for Test Case 1: %d\n", countSquares(matrix1, 3, colSize1));

    int m2[3][3] = {
        {1,0,1},
        {1,1,0},
        {1,1,0}
    };
    int* matrix2[3] = {m2[0], m2[1], m2[2]};
    int colSize2[1] = {3};
    printf("Output for Test Case 2: %d\n", countSquares(matrix2, 3, colSize2));

    return 0;
}

