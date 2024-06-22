#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int numberOfSubarrays(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> count;
        count[0] = 1;
        int prefixSum = 0;
        int result = 0;

        for (int num : nums) {
            prefixSum += num % 2; 
            if (count.find(prefixSum - k) != count.end()) {
                result += count[prefixSum - k];
            }
            count[prefixSum]++;
        }

        return result;
    }
};

// test case
int main() {
    Solution solution;

    std::vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;

    int result = solution.numberOfSubarrays(nums, k);

    std::cout << "number of nice subarrays: " << result << std::endl; 

    return 0;
}