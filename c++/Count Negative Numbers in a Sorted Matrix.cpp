#include <iostream>
#include <vector>

class Solution {
public:
    int countNegatives(std::vector<std::vector<int>>& grid) {
        int negative_count = 0;
        
        for (const auto& row : grid) {
            negative_count += binary_search(row);
        }

        return negative_count;
    }

private:
    int binary_search(const std::vector<int>& row) {
        int left = 0;
        int right = row.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (row[mid] < 0) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return row.size() - left;
    }
};

// Test case
int main() {
    std::vector<std::vector<int>> grid1 = {{4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};
    std::vector<std::vector<int>> grid2 = {{3, 2}, {1, 0}};

    Solution solution;

    std::cout << "Result of test Case 1: " << solution.countNegatives(grid1) << std::endl; // Expected: 8
    std::cout << "Result of test Case 2: " << solution.countNegatives(grid2) << std::endl; // Expected: 0

    return 0;
}
