#include <vector>
#include <iostream>


class Solution {
public:
     std::vector<int> targetIndices(std::vector<int>& nums, int target) {
        std::vector<int> result;
        std::vector<int> sorted = nums;             
        std::sort(sorted.begin(), sorted.end());
        int size = sorted.size();

        for(int i = 0; i < size; i++) {
            if (sorted[i] == target) {
    		    result.push_back(i);
            }
        }

        return result;
    }
};

// Helper
std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << "[";
    for (size_t i = 0; i < v.size(); i++) {
        os << v[i];
        if (i + 1 < v.size()) os << ", ";
    }
    return os << "]";
}

// Test cases
int main() {
    Solution sol;

    // case 1
    std::vector<int> nums1 = {1, 2, 5, 2, 3};
    int target1 = 2;
    std::cout<< "Result of test case 1: " << sol.targetIndices(nums1, target1) << std::endl;

    // case 2
    std::vector<int> nums2 = {1, 2, 5, 2, 3};
    int target2 = 3;
    std::cout<< "Result of test case 2: " << sol.targetIndices(nums2, target2) << std::endl;

    // case 3
    std::vector<int> nums3 = {1, 2, 5, 2, 3};
    int target3 = 5;
    std::cout<< "Result of test case 3: " << sol.targetIndices(nums3, target3) << std::endl;

    return 0;
}
