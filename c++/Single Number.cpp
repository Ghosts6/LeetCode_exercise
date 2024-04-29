#include <iostream>
#include <vector>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num;
        }
        return result;
    }
};

//  test case
int main() {
    Solution sol;
    std::vector<int> nums1 = {2, 2, 1};
    int result = sol.singleNumber(nums1);
    std::cout << "result : "<<result<< std::endl;
    return 0;
}