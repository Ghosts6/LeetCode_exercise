#include <stdio.h>

char findKthBitHelper(int n, int k) {
    if (n == 1) {
        return '0';  
    }
    int length = (1 << n) - 1;  
    int mid = (length + 1) / 2; 

    if (k == mid) {
        return '1';
    } else if (k < mid) {
        return findKthBitHelper(n - 1, k);  
    } else {
        char bit = findKthBitHelper(n - 1, length - k + 1);
        return bit == '0' ? '1' : '0';  
    }
}

char findKthBit(int n, int k) {
    return findKthBitHelper(n, k);
}

// Test case
int main() {
    // case 1
    int n1 = 3, k1 = 1;
    printf("Test case 1 - Expected: 0, Got: %c\n", findKthBit(n1, k1));
    
    // case 2
    int n2 = 4, k2 = 11;
    printf("Test case 2 - Expected: 1, Got: %c\n", findKthBit(n2, k2));
    
    // Additional cases
    int n3 = 2, k3 = 3;
    printf("Test case 3 - Expected: 1, Got: %c\n", findKthBit(n3, k3));
      
    return 0;
}
