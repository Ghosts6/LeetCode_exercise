#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    std::vector<std::vector<int>> diagonalSort(std::vector<std::vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        for (int i = 0; i < n; ++i) {
            sortDiagonal(mat, 0, i, m, n);
        }
        for (int i = 1; i < m; ++i) {
            sortDiagonal(mat, i, 0, m, n);
        }
        
        return mat;
    }
private:
    void sortDiagonal(std::vector<std::vector<int>>& mat, int row, int col, int m, int n) {
        std::vector<int> diagonal;
        while (row < m && col < n) {
            diagonal.push_back(mat[row][col]);
            ++row;
            ++col;
        }
        std::sort(diagonal.begin(), diagonal.end());
        row -= diagonal.size();
        col -= diagonal.size();
        for (int i = 0; i < diagonal.size(); ++i) {
            mat[row + i][col + i] = diagonal[i];
        }
    }
};

void printMatrix(const std::vector<std::vector<int>>& mat) {
    for (const auto& row : mat) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}
//  test case
int main() {
    Solution sol;
    std::vector<std::vector<int>> mat = {{3,3,1,1},{2,2,1,2},{1,1,1,2}};
    std::cout << "original matrix:" << std::endl;
    printMatrix(mat);
    std::vector<std::vector<int>> result = sol.diagonalSort(mat);
    std::cout << "\nmatrix after diagonal sort:" << std::endl;
    printMatrix(result);
    return 0;
}
