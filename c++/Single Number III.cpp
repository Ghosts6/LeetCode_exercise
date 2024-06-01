#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> singleNumber(std::vector<int>& nums) {
        std::unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        
        std::vector<int> result;
        for (const auto& pair : count) {
            if (pair.second == 1) {
                result.push_back(pair.first);
            }
        }
        
        return result;
    }
};
//  test case
int main() {
    Solution solution;
    
    std::vector<int> nums1 = {1, 2, 1, 3, 2, 5};
    std::vector<int> result1 = solution.singleNumber(nums1);
    std::cout << "result of test case: " << result1[0] << ", " << result1[1] << std::endl;

    return 0;
}
