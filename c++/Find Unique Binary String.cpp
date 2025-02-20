#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

class Solution {
    public:
        std::string findDifferentBinaryString(std::vector<std::string>& nums) {
            int n = nums.size();
            std::unordered_set<std::string> existing(nums.begin(), nums.end());
    
            for (int i = 0; i < (1 << n); ++i) {
                std::string candidate = toBinary(i, n);
                if (!existing.count(candidate)) return candidate;
            }
            return "";
        }
    
    private:
        std::string toBinary(int num, int length) {
            std::string result;
            for (int i = length - 1; i >= 0; --i)
                result += (num & (1 << i)) ? '1' : '0';
            return result;
        }
};
// Test case
int main() {
    Solution solution;

    // Case 1
    std::vector<std::string> nums1 = {"01", "10"};
    std::cout << "Result of test case 1: " << solution.findDifferentBinaryString(nums1) << std::endl; // Expected Output: "11"

    // Case 2
    std::vector<std::string> nums2 = {"00", "01"};
    std::cout << "Result of test case 2: " << solution.findDifferentBinaryString(nums2) << std::endl; // Expected Output: "11"

    // Case 3
    std::vector<std::string> nums3 = {"111", "011", "001"};
    std::cout << "Result of test case 3: " << solution.findDifferentBinaryString(nums3) << std::endl; // Expected Output: "101"

    return 0;
}
