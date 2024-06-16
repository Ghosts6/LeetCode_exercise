#include <iostream>
#include <vector>

class Solution {
public:
    int minPatches(std::vector<int>& nums, int n) {
        long miss = 1;
        int added = 0;
        int i = 0;
        
        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i];
                i++;
            } else {
                miss += miss;
                added++;
            }
        }
        
        return added;
    }
};

// test case
int main() {
    Solution solution;

    std::vector<int> nums1 = {1, 3};
    int n1 = 6;
    int result1 = solution.minPatches(nums1, n1);
    std::cout << "minimum number of patches required: " << result1 << std::endl;
    
    return 0;
}
