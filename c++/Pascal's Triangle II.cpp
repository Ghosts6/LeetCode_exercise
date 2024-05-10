#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> row(rowIndex + 1, 0);
        row[0] = 1;      
        for (int i = 1; i <= rowIndex; ++i) {
            for (int j = i; j > 0; --j) {
                row[j] += row[j - 1];
            }
        }  
        return row;
    }
};
//  test case
int main() {
    Solution solution;
    int rowIndex = 3;
    std::vector<int> row = solution.getRow(rowIndex);
    std::cout << "row " << rowIndex << " of Pascal's Triangle: ";
    for (int num : row) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}