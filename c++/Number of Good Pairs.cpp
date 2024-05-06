#include <vector>
#include <unordered_map>
#include <iostream>

class Solution {
public:
    int numIdenticalPairs(std::vector<int>& nums) {
        std::unordered_map<int, int> countMap;
        int goodPairs = 0;
        for (int num : nums) {
            countMap[num]++;
        }
        for (const auto& pair : countMap) {
            int count = pair.second;
            goodPairs += (count * (count - 1)) / 2;
        }     
        return goodPairs;
    }
};
//  test case
int main() {
    Solution sol;
    std::vector<int> nums = {1, 2, 3, 1, 1, 3};
    int goodPairs = sol.numIdenticalPairs(nums);
    std::cout << "number of good pairs: " << goodPairs << std::endl;
    return 0;
}