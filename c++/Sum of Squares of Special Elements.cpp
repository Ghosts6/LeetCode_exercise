#include <iostream>
#include <vector>

class Solution {
public:
    int sumOfSquares(std::vector<int>& nums) {
	size_t n = nums.size();
	int result = 0;

	if (n == 0 ) {
	    return 0;
	}

        for (int i = 1; i <= n / i; ++i) {
            if (n % i == 0) {
                result += nums[i - 1] * nums[i - 1];

                int j = n / i;
                if (j != i) {
                    result += nums[j - 1] * nums[j - 1];
                }
            }
        }

	return result;
    }
};

// Test cases

int main() {
    Solution sol;
    
    // case 1
    std::vector<int> nums1 = {1, 2, 3, 4};
    std::cout << "Result of test case 1 : " << sol.sumOfSquares(nums1) << std::endl;
    // case 2 
    std::vector<int> nums2 = {2, 7, 1, 19, 18, 3};
    std::cout << "Result of test case 2 : " << sol.sumOfSquares(nums2) << std::endl;

    return 0;
}
