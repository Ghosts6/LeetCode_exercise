#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int findMaxK(std::vector<int>& nums) {
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        int largestK = -1;
        for (int num : nums) {
            if (num > 0 && numSet.count(-num)) {
                largestK = std::max(largestK, num);
            }
        }
        return largestK;
    }
};

// test case
int main() {
    Solution sol;
    std::vector<int> gain = {-5, 1, 5, 0, 7, -7};
    int result = sol.findMaxK(gain);
    std::cout<<"result :"<<result<<std::endl;
    return 0;
}