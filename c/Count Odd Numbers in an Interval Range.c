#include <stdio.h>
#include <stdlib.h>

int countOdds(int low, int high);

// Test cases
int main() {
	// case 1
	int low1 = 3, high1 = 7;
	printf("Result of test case 1 : %d\n", countOdds(low1, high1)); // Expected: 3

	// case 2
	int low2 = 8, high2 = 10;
	printf("Result of test case 2 : %d\n", countOdds(low2, high2)); // Expected: 1

	return 0;
}

int countOdds(int low, int high) {
	if (low > high) return 0;
	
	int oddsHigh = (high + 1) >> 1;
	int oddsLow  = (low  >> 1);

	return oddsHigh - oddsLow;	
}
