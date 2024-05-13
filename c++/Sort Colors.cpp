#include <iostream>
#include <vector>

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        int red = 0, white = 0, blue = nums.size() - 1;
        while (white <= blue) {
            if (nums[white] == 0) {
                std::swap(nums[white], nums[red]);
                red++;
                white++;
            } else if (nums[white] == 1) {
                white++;
            } else {
                std::swap(nums[white], nums[blue]);
                blue--;
            }
        }
    }
};
// test case
int main() {
    Solution solution;
    std::vector<int> nums = {2,0,2,1,1,0};
    solution.sortColors(nums);
    std::cout << "sorted colors: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl; 
    return 0;
}
