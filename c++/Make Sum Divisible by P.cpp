#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric> 
#include <climits>  

class Solution {
public:
    int minSubarray(std::vector<int>& nums, int p) {
        int totalSum = std::accumulate(nums.begin(), nums.end(), 0);
        int targetMod = totalSum % p;

        if (targetMod == 0) {
            return 0;
        }

        std::unordered_map<int, int> modIndex;
        modIndex[0] = -1;  
        int currentMod = 0;
        int minLength = INT_MAX;

        for (int i = 0; i < nums.size(); ++i) {
            currentMod = (currentMod + nums[i]) % p;
            int neededMod = (currentMod - targetMod + p) % p;

            if (modIndex.find(neededMod) != modIndex.end()) {
                minLength = std::min(minLength, i - modIndex[neededMod]);
            }

            modIndex[currentMod] = i;
        }


        return minLength == INT_MAX ? -1 : minLength;
    }
};

// Test cases
int main() {
    Solution solution;
    
    // case 1
    std::vector<int> nums1 = {3, 1, 4, 2};
    int p1 = 6;
    std::cout << "Test Case 1 Output: " << solution.minSubarray(nums1, p1) << std::endl;  // Expected output: 1
    
    // case 2
    std::vector<int> nums2 = {6, 3, 5, 2};
    int p2 = 9;
    std::cout << "Test Case 2 Output: " << solution.minSubarray(nums2, p2) << std::endl;  // Expected output: 2
    
    return 0;
}
