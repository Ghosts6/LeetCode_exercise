#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    int beautifulSubsets(const std::vector<int>& nums, int k) {
        int result = 0;
        std::unordered_map<int, int> freq;
        backtrack(nums, k, 0, freq, result);
        return result;
    }
private:
    void backtrack(const std::vector<int>& nums, int k, int start, std::unordered_map<int, int>& freq, int& result) {
        if (start == nums.size()) return;
        
        for (int i = start; i < nums.size(); ++i) {
            if (freq[nums[i] - k] == 0 && freq[nums[i] + k] == 0) {
                freq[nums[i]]++;
                result++;
                backtrack(nums, k, i + 1, freq, result);
                freq[nums[i]]--;
            }
        }
    }
};
//  test case
int main() {
    Solution solution;
    
    std::vector<int> nums1 = {2, 4, 6};
    int k1 = 2;
    std::cout << "number of beautiful subsets for nums1: " << solution.beautifulSubsets(nums1, k1) << std::endl;

    std::vector<int> nums2 = {1, 2, 3, 4};
    int k2 = 1;
    std::cout << "number of beautiful subsets for nums2: " << solution.beautifulSubsets(nums2, k2) << std::endl;

    return 0;
}
