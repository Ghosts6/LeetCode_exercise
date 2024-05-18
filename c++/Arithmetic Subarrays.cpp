#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    std::vector<bool> checkArithmeticSubarrays(std::vector<int>& nums, std::vector<int>& l, std::vector<int>& r) {
        std::vector<bool> answer;
        
        for (size_t i = 0; i < l.size(); ++i) {
            if (isArithmetic(nums, l[i], r[i])) {
                answer.push_back(true);
            } else {
                answer.push_back(false);
            }
        }
        
        return answer;
    }
private:
    bool isArithmetic(const std::vector<int>& nums, int start, int end) {
        std::vector<int> subarray(nums.begin() + start, nums.begin() + end + 1);
        std::sort(subarray.begin(), subarray.end());
        
        int diff = subarray[1] - subarray[0];
        for (size_t i = 1; i < subarray.size(); ++i) {
            if (subarray[i] - subarray[i - 1] != diff) {
                return false;
            }
        }
        return true;
    }
};
//  test case
int main() {
    Solution solution;
    std::vector<int> nums = {4, 6, 5, 9, 3, 7};
    std::vector<int> l = {0, 0, 2};
    std::vector<int> r = {2, 3, 5}; 
    std::vector<bool> result = solution.checkArithmeticSubarrays(nums, l, r);
    
    for (bool res : result) {
        std::cout << (res ? "true" : "false") << std::endl;
    }
    
    return 0;
}