from typing import List

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
        
# Test cases
if __name__ == "__main__":
    sol = Solution();

    # case 1
    matrix1 = [
        [ 0, 1, 1, 1],
        [ 1, 1, 1, 1],
        [ 0, 1, 1, 1]
    ]
    print(f"Result of test case 1 : {sol.countSquares(matrix1)}") # Expected: 15

    # case 2
    matrix2 = [        
        [ 1, 0, 1],
        [ 1, 1, 0],
        [ 1, 1, 0]
    ]
    print(f"Result of test case 2 : {sol.countSquares(matrix2)}") # Expected: 7
