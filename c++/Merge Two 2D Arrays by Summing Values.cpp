#include <iostream>
#include <vector>

class Solution {
    public:
        std::vector<std::vector<int>> mergeArrays(std::vector<std::vector<int>>& nums1, std::vector<std::vector<int>>& nums2) {
            std::vector<std::vector<int>> result;
            int i = 0, j = 0, m = nums1.size(), n = nums2.size();
    
            while (i < m && j < n) {
                if (nums1[i][0] < nums2[j][0]) {
                    result.push_back(nums1[i++]);
                } else if (nums1[i][0] > nums2[j][0]) {
                    result.push_back(nums2[j++]);
                } else {
                    result.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                    i++, j++;
                }
            }
            
            while (i < m) result.push_back(nums1[i++]);
            while (j < n) result.push_back(nums2[j++]);
    
            return result;
        }
    };

// Helper function
void print2DVector(const std::vector<std::vector<int>>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << "[";
        for (size_t j = 0; j < vec[i].size(); ++j) {
            std::cout << vec[i][j];
            if (j < vec[i].size() - 1) std::cout << ",";
        }
        std::cout << "]";
        if (i < vec.size() - 1) std::cout << ",";
    }
    std::cout << "]" << std::endl;
}

// Test cases
int main(){
    Solution solution;
    // case 1
    std::vector<std::vector<int>> nums1_1 = {{1,2},{2,3},{4,5}};
    std::vector<std::vector<int>> nums1_2 = {{1,4},{3,2},{4,1}};
    std::vector<std::vector<int>> result1 = solution.mergeArrays(nums1_1, nums1_2);
    std::cout << "result of test case 1: ";
    print2DVector(result1); // Expected Output: [[1,6],[2,3],[3,2],[4,6]]

    // case 2
    std::vector<std::vector<int>> nums2_1 = {{2,4},{3,6},{5,5}};
    std::vector<std::vector<int>> nums2_2 = {{1,3},{4,3}};
    std::vector<std::vector<int>> result2 = solution.mergeArrays(nums2_1, nums2_2);
    std::cout << "result of test case 2: ";
    print2DVector(result2); // Expected Output: [[1,3],[2,4],[3,6],[4,3],[5,5]]

    return 0;
}