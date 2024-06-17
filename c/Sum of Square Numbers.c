#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool judgeSquareSum(int c) {
    if (c < 0) return false;
    
    long long left = 0;
    long long right = (long long)sqrt(c);
    
    while (left <= right) {
        long long sum = left * left + right * right;
        if (sum == c) {
            return true;
        } else if (sum < c) {
            left++;
        } else {
            right--;
        }
    }
    return false;
}

// test case
int main() {
    int c = 5;
    bool result = judgeSquareSum(c);
    printf("can %d be expressed as the sum of squares of two integers? %s\n", c, result ? "Yes" : "No");

    return 0;
}