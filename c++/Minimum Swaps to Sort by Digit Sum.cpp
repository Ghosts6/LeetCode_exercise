#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    int digitSum(int n) {
	int sum = 0;
	while (n > 0) {
	    sum += n % 10;
	    n /= 10;
	}
	return sum;
    }

    int minSwaps(std::vector<int>& nums) {
	int n = nums.size();
	std::vector<int> sorted = nums;

	std::sort(sorted.begin(), sorted.end(), [this](int a, int b) {
	    int sumA = digitSum(a);
	    int sumB = digitSum(b);
	    if (sumA != sumB) return sumA < sumB;
	    return a < b;
	});

	std::unordered_map<int, int> pos;
	for (int i = 0; i < n; ++i) {
	    pos[sorted[i]] = i;
	}

	std::vector<bool> visited(n, false);
	int swaps = 0;

	for (int i = 0; i < n; ++i) {
	    if (visited[i] || pos[nums[i]] == i) continue;

	    int cycleSize = 0;
	    int j = i;
	    while (!visited[j]) {
		visited[j] = true;
		j = pos[nums[j]];
		cycleSize++;
	    }
	    swaps += cycleSize - 1;
	}

	return swaps;
    }
};

// Test cases
int main() {
    Solution sol;
    // case 1
    std::vector<int> nums1 = {37, 100};
    std::cout << "Result of test case 1: " << sol.minSwaps(nums1) << std::endl;

    // case 2
    std::vector<int> nums2 = {22, 14, 33, 7};
    std::cout << "Result of test case 2: " << sol.minSwaps(nums2) << std::endl;

    // case 3
    std::vector<int> nums3 = {18, 43, 34, 16};
    std::cout << "Result of test case 3: " << sol.minSwaps(nums3) << std::endl;

    return 0;
}
