#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(const std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> answer(n, 1);

        for (int i = 1; i < n; ++i) {
            answer[i] = answer[i - 1] * nums[i - 1];
        }

        int rightProduct = 1;
        for (int i = n - 1; i >= 0; --i) {
            answer[i] = answer[i] * rightProduct;
            rightProduct *= nums[i];
        }
        
        return answer;
    }
};
//  test case
int main() {
    Solution sol;

    std::vector<int> nums = {1, 2, 3, 4};
    std::vector<int> result = sol.productExceptSelf(nums);
    
    std::cout << "result array: ";
    for (int val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    
    return 0;
}
