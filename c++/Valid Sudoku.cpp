#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::vector<std::unordered_set<char>> rows(9);
        std::vector<std::unordered_set<char>> cols(9);
        std::vector<std::unordered_set<char>> boxes(9);

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char current = board[i][j];
                if (current == '.') continue;
                if (rows[i].count(current) || cols[j].count(current) || boxes[(i / 3) * 3 + j / 3].count(current))
                    return false;
                rows[i].insert(current);
                cols[j].insert(current);
                boxes[(i / 3) * 3 + j / 3].insert(current);
            }
        }

        return true;
    }
};
//  test case
int main() {
    Solution solution;
    std::vector<std::vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    bool isValid = solution.isValidSudoku(board);
    std::cout << "is the Sudoku board valid? " << (isValid ? "Yes" : "No") << std::endl;
    return 0;
}