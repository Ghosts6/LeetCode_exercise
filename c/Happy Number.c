#include <stdio.h>
#include <stdbool.h>

inline int getSumOfSquares(int num) {
    int sum = 0;
    while (num > 0) {
        int digit = num % 10;
        sum += digit * digit;
        num /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    int slow = n;
    int fast = getSumOfSquares(n);

    while (fast != 1 && slow != fast) {
        slow = getSumOfSquares(slow);
        fast = getSumOfSquares(getSumOfSquares(fast));
    }

    return fast == 1;
}
//  test case
int main() {
    int n = 19; 
    if (isHappy(n)) {
        printf("%d is a happy number.\n", n);
    } else {
        printf("%d is not a happy number.\n", n);
    }
    return 0;
}
