# 📜 Intuition

## 💡 Intuition
The core idea is dynamic programming. For each cell `(i, j)` containing a `1`, we can determine the size of the largest square that has this cell as its bottom-right corner. This size depends on the values of its adjacent neighbors: top, left, and top-left. By calculating this for every cell, we can sum up these sizes to get the total number of squares.

## 🛠️  Approach
We define a DP state, `dp[i][j]`, as the side length of the largest square of all ones with its bottom-right corner at `(i, j)`.

The recurrence relation is:
If `matrix[i][j] == 1`, then `dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])`.
If `matrix[i][j] == 0`, then `dp[i][j] = 0`.

The base cases are the cells in the first row and column, where `dp[i][j]` is simply `matrix[i][j]`.

The total number of squares is the sum of all `dp[i][j]` values. This approach can be space-optimized by either modifying the input matrix in-place (O(1) space) or by using a 1D DP array (O(n) space), as the calculation for each row only depends on the previous row.



## ⏰ Complexity
- Time complexity: O(m * n)
We iterate through each cell of the matrix once.

- Space complexity: O(1)
The provided C, C++, TypeScript, and Python solutions modify the matrix in-place. The Java solution is optimized to O(n) without modifying the input, but an O(1) space version is also possible.


---

## 💻 Code
```C []
int countSquares(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize, n = matrixColSize[0], count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1 && i > 0 && j > 0) {
                int min = matrix[i-1][j];
                if (matrix[i][j-1] < min) min = matrix[i][j-1];
                if (matrix[i-1][j-1] < min) min = matrix[i-1][j-1];
                matrix[i][j] = min + 1;
            }
            count += matrix[i][j];
        }
    }
    return count;
}
```
```C++ []
class Solution {
public:
    int countSquares(std::vector<std::vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int count = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1 && i > 0 && j > 0) {
                    matrix[i][j] = std::min(std::min(matrix[i - 1][j], matrix[i][j - 1]), matrix[i - 1][j - 1]) + 1;
                }
                count += matrix[i][j];
            }
        }

        return count;
    }
};
```
```java []
class Solution {
    public int countSquares(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int[] dp = new int[n + 1];
        int count = 0;
        int prev = 0;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int temp = dp[j];
                if (matrix[i - 1][j - 1] == 1) {
                    dp[j] = Math.min(Math.min(dp[j], dp[j - 1]), prev) + 1;
                    count += dp[j];
                } else {
                    dp[j] = 0;
                }
                prev = temp;
            }
        }

        return count;
    }

}
```
```ts []
function countSquares(matrix: number[][]): number {
    const m = matrix.length;
    const n = matrix[0].length;
    let count = 0;

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (matrix[i][j] === 1 && i > 0 && j > 0) {
                matrix[i][j] = Math.min(
                    matrix[i - 1][j],
                    matrix[i][j - 1],
                    matrix[i - 1][j - 1]
                ) + 1;
            }
            count += matrix[i][j];
        }
    }

    return count;
}
```
```python3 []
class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        if not matrix or not matrix[0]:
            return 0

        m, n = len(matrix), len(matrix[0])
        count = 0

        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 1 and i > 0 and j > 0:
                    matrix[i][j] = min(matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]) + 1
                count += matrix[i][j]

        return count
```
