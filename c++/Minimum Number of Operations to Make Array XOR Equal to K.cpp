#include <iostream>
#include <vector>


class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {
        int finalXor = 0;
        for (int n : nums) {
            finalXor = finalXor ^ n;
        }
        int count = 0;
        while (k || finalXor) {
            if ((k % 2) != (finalXor % 2)){
                count++;
            }
            k /= 2;
            finalXor /= 2;
        }
        return count;
    }
};

//  test case 
int main(){
    Solution sol;
    std::vector<int> nums = {0, 1, 2, 3, 4, 5};
    int k = 6;
    std::cout << "minimum operations: " << sol.minOperations(nums, k) << std::endl;
    return 0;
}
