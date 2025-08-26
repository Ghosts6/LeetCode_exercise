#include <stdio.h>

int areaOfMaxDiagonal(int** dimensions, int dimensionsSize, int* dimensionsColSize) {
    int maxArea = 0;
    long long maxDiagSq = -1;
    for (int i = 0; i < dimensionsSize; i++) {
        int l = dimensions[i][0], w = dimensions[i][1];
        long long diagSq = (long long)l * l + (long long)w * w;
        int area = l * w;
        if (diagSq > maxDiagSq || (diagSq == maxDiagSq && area > maxArea)) {
            maxDiagSq = diagSq;
            maxArea = area;
        }
    }
    return maxArea;
}

// Test cases
int main() {
    // case 1
    int d1[2][2] = {{9,3},{8,6}};
    int* p1[2] = {d1[0], d1[1]};
    int colSize1 = 2;
    printf("Result of test case 1 : %d\n", areaOfMaxDiagonal(p1, 2, &colSize1)); // Expected: 48

    // case 2
    int d2[2][2] = {{3,4},{4,3}};
    int* p2[2] = {d2[0], d2[1]};
    int colSize2 = 2;
    printf("Result of test case 2 : %d\n", areaOfMaxDiagonal(p2, 2, &colSize2)); // Expected: 12

    return 0;
}

