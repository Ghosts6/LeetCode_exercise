#include <vector>
#include <unordered_map>
#include <cassert>
#include <iostream>

class Solution {
public:
    int subarraysDivByK(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> prefixSumFreq;
        prefixSumFreq[0] = 1;
        int prefixSum = 0, count = 0;

        for (int num : nums) {
            prefixSum += num;
            int remainder = (prefixSum % k + k) % k;
            if (prefixSumFreq.find(remainder) != prefixSumFreq.end()) {
                count += prefixSumFreq[remainder];
            }
            prefixSumFreq[remainder]++;
        }

        return count;
    }
};
//  test case
int main() {
    Solution sol;

    std::vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;
    assert(sol.subarraysDivByK(nums, k) == 7);

    return 0;
}
