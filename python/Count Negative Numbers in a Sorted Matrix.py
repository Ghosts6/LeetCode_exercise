class Solution:
    def countNegatives(self, grid):
        def binary_search(row):
            left, right = 0, len(row) - 1
            while left <= right:
                mid = (left + right) // 2
                if row[mid] < 0:
                    right = mid - 1  
                else:
                    left = mid + 1   
            return len(row) - left  

        negative_count = 0
        
        for row in grid:
            negative_count += binary_search(row)

        return negative_count

# Test case
if __name__ == "__main__":
    grid1 = [[4, 3, 2, -1], [3, 2, 1, -1], [1, 1, -1, -2], [-1, -1, -2, -3]]
    grid2 = [[3, 2], [1, 0]]

    solution = Solution()

    print("Test Case 1: ", solution.countNegatives(grid1))  # Output: 8
    print("Test Case 2: ", solution.countNegatives(grid2))  # Output: 0
