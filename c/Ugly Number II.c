#include <stdio.h>

int nthUglyNumber(int n) {
    int uglyNumbers[n];
    uglyNumbers[0] = 1;  

    int i2 = 0, i3 = 0, i5 = 0;  
    int nextMultipleOf2 = 2;
    int nextMultipleOf3 = 3;
    int nextMultipleOf5 = 5;
    int nextUglyNumber;

    for (int i = 1; i < n; i++) {
        nextUglyNumber = nextMultipleOf2 < nextMultipleOf3 ? (nextMultipleOf2 < nextMultipleOf5 ? nextMultipleOf2 : nextMultipleOf5) : (nextMultipleOf3 < nextMultipleOf5 ? nextMultipleOf3 : nextMultipleOf5);
        uglyNumbers[i] = nextUglyNumber;

        if (nextUglyNumber == nextMultipleOf2) {
            i2++;
            nextMultipleOf2 = uglyNumbers[i2] * 2;
        }
        if (nextUglyNumber == nextMultipleOf3) {
            i3++;
            nextMultipleOf3 = uglyNumbers[i3] * 3;
        }
        if (nextUglyNumber == nextMultipleOf5) {
            i5++;
            nextMultipleOf5 = uglyNumbers[i5] * 5;
        }
    }
    return uglyNumbers[n - 1];  
}
// Test cases
int main() {
    int test_cases[] = {10, 1, 15, 100, 7};
    int expected_results[] = {12, 1, 24, 1536, 8};
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < num_tests; i++) {
        int n = test_cases[i];
        int result = nthUglyNumber(n);
        if (result == expected_results[i]) {
            printf("Test case %d passed. Input: %d, Output: %d\n", i + 1, n, result);
        } else {
            printf("Test case %d failed. Input: %d, Expected: %d, Got: %d\n", i + 1, n, expected_results[i], result);
        }
    }

    return 0;
}