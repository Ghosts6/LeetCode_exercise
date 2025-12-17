#include <stdio.h>

long long getDescentPeriods(int* prices, int pricesSize);

// Test cases
int main() {
    // case 1
    int prices[] = {3, 2, 1, 4};
    printf("Result of test case 1 : %lld\n", getDescentPeriods(prices, 4)); // Expected: 7

    // case 2
    int prices2[] = {8, 6, 7, 7};
    printf("Result of test case 2: %lld\n", getDescentPeriods(prices2, 4)); // Expected: 4
    
    // case 3
    int prices3[] = {1};
    printf("Result of test case 3: %lld\n", getDescentPeriods(prices3, 1)); // Expected: 1

    return 0;
}

long long getDescentPeriods(int* prices, int pricesSize) {
    long totalPeriods = 0;
    int currentLength = 1;
        
    if (pricesSize == 0) {
        return 0;
    }

    totalPeriods = 1;

    for (int i = 1; i < pricesSize; i++) {
            
        if (prices[i] == prices[i - 1] - 1) {
            currentLength++;
        } else {
            currentLength = 1;
        }
            
        totalPeriods += currentLength;
    }

    return totalPeriods;
}
