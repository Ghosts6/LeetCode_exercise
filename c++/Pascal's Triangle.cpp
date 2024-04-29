#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> triangle;
        for (int i = 0; i < numRows; ++i) {
            std::vector<int> row(i + 1, 1);
            for (int j = 1; j < i; ++j) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            triangle.push_back(row);
        }
        return triangle;
    }
};
// test case
int main() {
    Solution sol;
    int numRows = 5;
    std::vector<std::vector<int>> result = sol.generate(numRows);
    std::cout << "Pascal's Triangle for numRows = " << numRows << ":\n";
    for (const auto& row : result) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << "\n";
    }
    return 0;
}