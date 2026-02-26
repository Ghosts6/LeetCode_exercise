#include <stdio.h>
#include <string.h>

int numSteps(const char* s) {
    int n = strlen(s);
    int steps = 0;
    int carry = 0;

    // Traverse from right to left (excluding most significant bit)
    for (int i = n - 1; i > 0; --i) {
        int bit = (s[i] - '0') + carry;

        if (bit % 2 == 0) {
            // Even -> divide by 2
            steps += 1;
        } else {
            // Odd -> add 1 then divide
            steps += 2;
            carry = 1;
        }
    }

    return steps + carry;
}

int main() {
    const char* s = "1101";
    int result = numSteps(s);
    printf("result of test case: %d (Expected: 6)\n", result);
    return 0;
}
