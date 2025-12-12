#include <stdio.h>

int countPermutations(int* complexity, int complexitySize);

// test cases
int main() {
	// case 1
	int complexity1[] = {1, 2, 3};
	printf("Result of test case 1 : %d\n", countPermutations(complexity1, 3)); // Expected: 2

	// case 2
	int complexity2[] = {3, 3, 3, 4, 4, 4};
	printf("Result of test case 2 : %d\n", countPermutations(complexity2, 6)); // Expected: 0
	
	return 0;
}

int countPermutations(int* complexity, int complexitySize) {
    int n = complexitySize;
    int first = complexity[0];
    for (int i = 1; i < n; i++) {
        if (complexity[i] <= first) {
            return 0;
        }
    }
    long long ans = 1;
    const int MOD = 1000000007;
    for (int i = 2; i < n; i++) {
        ans = ans * i % MOD;
    }
    return ans;
}
