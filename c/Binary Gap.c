#include <stdio.h>

// Prototype
int binaryGap(int n);

// Test cases
int main() {
    // case 1
    int n1 = 22;
    printf("Result of test case 1 : %d\n", binaryGap(n1)); // Expected: 2

    // case 2
    int n2 = 8;
    printf("Result of test case 2 : %d\n", binaryGap(n2)); // Expected: 0

    // case 3
    int n3 = 5;
    printf("Result of test case 3 : %d\n", binaryGap(n3)); // Expected: 2

    return 0;
}

int binaryGap(int n) {
    int last = -1;
    int maxDist = 0;
    int pos = 0;

    while (n > 0) {
        if (n & 1) {
            if (last != -1) {
                int dist = pos - last;
                if (dist > maxDist)
                    maxDist = dist;
            }
            last = pos;
        }
        n >>= 1;
        pos++;
    }

    return maxDist;
}
