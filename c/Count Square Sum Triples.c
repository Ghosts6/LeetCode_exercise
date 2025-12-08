#include <stdio.h>
#include <stdlib.h>

int countTriples(int n);

// Test cases
int main() {
	// case 1
	int n1 = 5;
	printf("Result of test case 1 : %d\n", countTriples(n1)); // Expected: 2
	
	// case 2
	int n2 = 10;
	printf("Result of test case 2 : %d\n", countTriples(n2)); // Expected: 4

	return 0;
}

int countTriples(int n) {
    int maxSq = n * n;
    int *sqToVal = (int*)calloc(maxSq + 1, sizeof(int));

    for (int c = 1; c <= n; c++) {
        sqToVal[c * c] = c;
    }

    int count = 0;

    for (int a = 1; a <= n; a++) {
        int a2 = a * a;
        for (int b = 1; b <= n; b++) {
            int s = a2 + b * b;
            if (s <= maxSq && sqToVal[s] != 0) {
                count++;
            }
        }
    }

    free(sqToVal);
    return count;
}

