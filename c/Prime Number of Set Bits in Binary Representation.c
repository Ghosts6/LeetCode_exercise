#include <stdio.h>

// prototype
int countPrimeSetBits(int left, int right);

int main() {
    // Case 1
    int left1 = 6, right1 = 10;
    printf("Result of test case 1: %d\n", countPrimeSetBits(left1, right1));

    // Case 2
    int left2 = 10, right2 = 15;
    printf("Result of test case 2: %d\n", countPrimeSetBits(left2, right2));

    return 0;
}

int countPrimeSetBits(int left, int right) {
    int totalPrimes = 0;
    unsigned int primeMask = 0xA28A28AC;

    for (int i = left; i <= right; i++) {
        int count = 0;
        int n = i;
        
        // Brian Kernighan’s Algorithm to count set bits
        while (n > 0) {
            n &= (n - 1);
            count++;
        }

        // Check if the count is a prime using the mask
        if ((primeMask >> count) & 1) {
            totalPrimes++;
        }
    }

    return totalPrimes;
}
