#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <climits>

class Solution {
public:
    double findMedianSortedArrays(const std::vector<int>& nums1, const std::vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int half_len = (m + n + 1) / 2;

        int left = 0, right = m;

        while (left <= right) {
            int i = (left + right) / 2;
            int j = half_len - i;

            int nums1_left_max = (i == 0) ? INT_MIN : nums1[i - 1];
            int nums1_right_min = (i == m) ? INT_MAX : nums1[i];
            int nums2_left_max = (j == 0) ? INT_MIN : nums2[j - 1];
            int nums2_right_min = (j == n) ? INT_MAX : nums2[j];

            if (nums1_left_max <= nums2_right_min && nums2_left_max <= nums1_right_min) {
                if ((m + n) % 2 == 1) {
                    return std::max(nums1_left_max, nums2_left_max);
                }
                return (std::max(nums1_left_max, nums2_left_max) + std::min(nums1_right_min, nums2_right_min)) / 2.0;
            }
            else if (nums1_left_max > nums2_right_min) {
                right = i - 1;
            }
            else {
                left = i + 1;
            }
        }
        throw std::invalid_argument("The arrays are not sorted or input is invalid.");
    }
};

// TestCases
int main() {
    Solution solution;

    // Case 1
    std::vector<int> nums1 = {1, 3};
    std::vector<int> nums2 = {2};
    double expected_output1 = 2.0;
    double result1 = solution.findMedianSortedArrays(nums1, nums2);
    std::cout << "Test Case 1: ";
    std::cout << std::fixed << std::setprecision(5) << result1 << " (Expected: " << expected_output1 << ")\n";

    // Case 2
    std::vector<int> nums1_2 = {1, 2};
    std::vector<int> nums2_2 = {3, 4};
    double expected_output2 = 2.5;
    double result2 = solution.findMedianSortedArrays(nums1_2, nums2_2);
    std::cout << "Test Case 2: ";
    std::cout << std::fixed << std::setprecision(5) << result2 << " (Expected: " << expected_output2 << ")\n";

    return 0;
}

