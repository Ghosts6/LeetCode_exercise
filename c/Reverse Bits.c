#include<stdio.h>

int reverseBits(int n);

int main() {
    // case 1
    int n1 = 43261596;
    printf("Result of test case 1 : %d\n", reverseBits(n1)); // Expected: 964176192

    // case 2
    int n2 = 2147483644;
    printf("Result of test case 2 : %d\n", reverseBits(n2)); // Expected: 1073741822

    return 0;
}

int reverseBits(int n) {
    unsigned int x = (unsigned int)n;
    unsigned int res = 0;

    for (int i = 0; i < 32; i++) {
        res = (res << 1) | (x & 1);
        x >>= 1;
    }

    return (int)res;
}
