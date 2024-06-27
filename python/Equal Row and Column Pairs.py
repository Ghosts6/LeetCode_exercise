from typing import List

class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        n = len(grid)
        count = 0

        column_tuples = {}

        for i in range(n):
            row_tuple = tuple(grid[i])

            if row_tuple not in column_tuples:
                column_tuples[row_tuple] = 0
            
            column_tuples[row_tuple] += 1
        
        for j in range(n):
            column_tuple = tuple(grid[i][j] for i in range(n))
            
            if column_tuple in column_tuples:
                count += column_tuples[column_tuple]
        
        return count

# test case
if __name__ == "__main__":
    solution = Solution()
    
    # un match case
    
    grid = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ]
    print("case 1 - Expected: 0, Got:", solution.equalPairs(grid))  
    
    # match case
    
    grid = [
        [1, 1, 1],
        [1, 1, 1],
        [1, 1, 1]
    ]
    print("case2  - Expected: 9, Got:", solution.equalPairs(grid)) 
  