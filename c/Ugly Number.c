#include <stdio.h>
#include <stdbool.h>

bool isUgly(int n) {
    if (n <= 0) return false; 

    while (n % 2 == 0) n /= 2;
    while (n % 3 == 0) n /= 3;
    while (n % 5 == 0) n /= 5;

    return n == 1;
}
//  test case
int main() {
    int test_cases[] = {6, 1, 14, 0, 30, 8, 25, -5};
    bool expected_results[] = {true, true, false, false, true, true, true, false};
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < num_tests; i++) {
        int n = test_cases[i];
        bool result = isUgly(n);
        if (result == expected_results[i]) {
            printf("Test case %d passed. Input: %d, Output: %s\n", i + 1, n, result ? "true" : "false");
        } else {
            printf("Test case %d failed. Input: %d, Expected: %s, Got: %s\n", i + 1, n, expected_results[i] ? "true" : "false", result ? "true" : "false");
        }
    }
    return 0;
}