#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> findDegrees(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        std::vector<int> ans(n, 0);
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                ans[i] += matrix[i][j];
        
        return ans;
    }
};

int main() {
    Solution sol;

    // case 1
    std::vector<std::vector<int>> m1 = {{0,1,1},{1,0,1},{1,1,0}};
    std::vector<int> r1 = sol.findDegrees(m1);
    std::cout << "Result of test case 1: ";
    for (int x : r1) std::cout << x << " ";
    std::cout << std::endl;

    // case 2
    std::vector<std::vector<int>> m2 = {{0,1,0},{1,0,0},{0,0,0}};
    std::vector<int> r2 = sol.findDegrees(m2);
    std::cout << "Result of test case 2: ";
    for (int x : r2) std::cout << x << " ";
    std::cout << std::endl;

    // case 3
    std::vector<std::vector<int>> m3 = {{0}};
    std::vector<int> r3 = sol.findDegrees(m3);
    std::cout << "Result of test case 3: ";
    for (int x : r3) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}
