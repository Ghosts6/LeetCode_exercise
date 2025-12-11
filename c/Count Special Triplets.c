#include <stdio.h>
#include <stdint.h>

int specialTriplets(int* nums, int numsSize);

int main() {
	// case 1
	int nums1[] = {6, 3, 6};
	printf("Result of test case 1 : %d\n", specialTriplets(nums1, 3)); // Expected: 1

	// case 2
	int nums2[] = {0, 1, 0, 0};
	printf("Result of test case 2 : %d\n", specialTriplets(nums2, 4)); // Expected: 1
	
	// case 3
	int nums3[] = {8, 4, 2, 8, 4};
	printf("Result of test case 3 : %d\n", specialTriplets(nums3, 5)); // Expected: 3
	
	return 0;
}

int specialTriplets(int* nums, int numsSize) {
    const int MOD = 1000000007;
    static int left[100001], right[100001];

    for (int i = 0; i < 100001; i++) {
        left[i] = 0;
        right[i] = 0;
    }

    for (int i = 0; i < numsSize; i++) {
        right[nums[i]]++;
    }

    long long ans = 0;

    for (int j = 0; j < numsSize; j++) {
        int v = nums[j];
        right[v]--;
        int x = v * 2;
        if (x <= 100000) {
            long long a = left[x];
            long long b = right[x];
            ans = (ans + (a * b) % MOD) % MOD;
        }
        left[v]++;
    }

    return (int)ans;
}
