# 📏Valid Sudoku📏

# Approach
My approach to solving the Sudoku problem involves iterating through each cell of the board and keeping track of the numbers seen in each row, column, and 3x3 sub-grid. I'll use sets to efficiently check for duplicates and ensure that the Sudoku board follows the given rules.

# Complexity
- Time complexity:
The time complexity of my approach is \(O(1)\) because we are iterating over a fixed-size Sudoku board (9x9) and performing constant-time operations for each cell.

- Space complexity:
The space complexity is also \(O(1)\) since we only use additional space to store sets representing the numbers seen in each row, column, and sub-grid, and the size of these sets is constant regardless of the input size.


# Code
### C++
```c++
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
```
### Python
```python
class Solution(object):
    def isValidSudoku(self, board):
        rows = [set() for _ in range(9)]
        cols = [set() for _ in range(9)]
        boxes = [set() for _ in range(9)]

        for i in range(9):
            for j in range(9):
                current = board[i][j]
                if current == '.':
                    continue
                if current in rows[i] or current in cols[j] or current in boxes[(i // 3) * 3 + j // 3]:
                    return False
                rows[i].add(current)
                cols[j].add(current)
                boxes[(i // 3) * 3 + j // 3].add(current)

        return True


```
### Java script
```javascript
var isValidSudoku = function(board) {
    var rows = new Array(9).fill().map(() => new Set());
    var cols = new Array(9).fill().map(() => new Set());
    var boxes = new Array(9).fill().map(() => new Set());

    for (var i = 0; i < 9; ++i) {
        for (var j = 0; j < 9; ++j) {
            var current = board[i][j];
            if (current === '.') continue;
            if (rows[i].has(current) || cols[j].has(current) || boxes[Math.floor(i / 3) * 3 + Math.floor(j / 3)].has(current))
                return false;
            rows[i].add(current);
            cols[j].add(current);
            boxes[Math.floor(i / 3) * 3 + Math.floor(j / 3)].add(current);
        }
    }

    return true;
};
```