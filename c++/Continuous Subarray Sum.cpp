#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    bool checkSubarraySum(std::vector<int>& nums, int k) {

        std::unordered_map<int, int> remainderIndexMap;

        remainderIndexMap[0] = -1;

        int runningSum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            runningSum += nums[i];
            int remainder = runningSum % k;
            if (remainder < 0) {
                remainder += k;
            }

            if (remainderIndexMap.find(remainder) != remainderIndexMap.end()) {
                if (i - remainderIndexMap[remainder] > 1) {
                    return true;
                }
            } else {
                remainderIndexMap[remainder] = i;
            }
        }

        return false;
    }
};
//  test cases
int main(){
    Solution sol;
    
    std::vector<int> nums1 = {23, 2, 4, 6, 7};
    int k1 = 6;
    std::cout << "Test 1: " << (sol.checkSubarraySum(nums1, k1) ? "Passed" : "Failed") << std::endl;

    std::vector<int> nums2 = {23, 2, 6, 4, 7};
    int k2 = 6;
    std::cout << "Test 2: " << (sol.checkSubarraySum(nums2, k2) ? "Passed" : "Failed") << std::endl;

    return 0;
}