from typing import List

class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        """Return count of positions where mat[i][j] == 1 and row i and column j contain no other 1s."""
        m, n = len(mat), len(mat[0])
        
        row_count = [0] * m
        col_count = [0] * n
        
        # Count 1s in each row and column
        for i in range(m):
            for j in range(n):
                if mat[i][j]:
                    row_count[i] += 1
                    col_count[j] += 1
        
        # Count special positions
        special = 0
        for i in range(m):
            if row_count[i] == 1:
                for j in range(n):
                    if mat[i][j] and col_count[j] == 1:
                        special += 1
        
        return special

# Test cases
if __name__ == "__main__":
    sol = Solution()

    # case 1
    mat1 = [[1,0,0],[0,0,1],[1,0,0]]
    print(f"Result of test case 1 : {sol.numSpecial(mat1)}") # Expected: 1

    # case 2
    mat2 = [[1,0,0],[0,1,0],[0,0,1]]
    print(f"Result of test case 2 : {sol.numSpecial(mat2)}") # Expected: 3
