#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    std::vector<int> numberGame(std::vector<int>& nums) {
        std::vector<int> arr;
        std::sort(nums.begin(), nums.end());

        while (!nums.empty()) {
            int aliceMove = nums.front();
            nums.erase(nums.begin());
            if (!nums.empty()) {
                int bobMove = nums.front();
                nums.erase(nums.begin());
                arr.push_back(bobMove);
            }
            arr.push_back(aliceMove);
        }

        return arr;
    }
};
// test case
int main() {
    std::vector<int> nums = {1, 3, 5, 2, 4, 6}; 
    Solution solution;
    std::vector<int> result = solution.numberGame(nums);
    
    std::cout << "result of array: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
