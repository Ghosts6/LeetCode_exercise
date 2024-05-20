#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int addedInteger(std::vector<int>& nums1, std::vector<int>& nums2) {
        if (nums1.size() != nums2.size()) {
            throw std::invalid_argument("Arrays must be of the same length");
        }

        int min1 = *std::min_element(nums1.begin(), nums1.end());
        int min2 = *std::min_element(nums2.begin(), nums2.end());

        return min2 - min1;
    }
};
//  test case
int main() {
    Solution solution;
    std::vector<int> nums1_1 = {2, 6, 4};
    std::vector<int> nums2_1 = {9, 7, 5};

    try {
        int x = solution.addedInteger(nums1_1, nums2_1);
        std::cout << "The integer x is: " << x << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
