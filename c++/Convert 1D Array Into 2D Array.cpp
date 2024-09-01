#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> construct2DArray(std::vector<int>& original, int m, int n) {
        if (original.size() != m * n) {
            return {};
        }
        
        std::vector<std::vector<int>> result(m, std::vector<int>(n));
        for (int i = 0; i < original.size(); ++i) {
            result[i / n][i % n] = original[i];
        }
        
        return result;
    }
};
//  Test case
int main() {
    Solution solution;
    std::vector<int> original1 = {1, 2, 3, 4};
    int m1 = 2, n1 = 2;
    std::vector<std::vector<int>> result1 = solution.construct2DArray(original1, m1, n1);

    std::cout << "Test Case 1: " << std::endl;
    for (const auto& row : result1) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    std::vector<int> original2 = {1, 2, 3};
    int m2 = 1, n2 = 3;
    std::vector<std::vector<int>> result2 = solution.construct2DArray(original2, m2, n2);

    std::cout << "Test Case 2: " << std::endl;
    for (const auto& row : result2) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}