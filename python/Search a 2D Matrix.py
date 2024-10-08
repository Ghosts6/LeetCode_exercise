class Solution:
    def searchMatrix(self, matrix, target):
        if not matrix or not matrix[0]:
            return False
        
        m, n = len(matrix), len(matrix[0])
        left, right = 0, m * n - 1

        while left <= right:
            mid = (left + right) // 2
            row, col = divmod(mid, n)
            mid_val = matrix[row][col]

            if mid_val == target:
                return True
            elif mid_val < target:
                left = mid + 1
            else:
                right = mid - 1

        return False

# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # case 1
    matrix1 = [[1,3,5,7], [10,11,16,20], [23,30,34,60]]
    target1 = 3
    print(solution.searchMatrix(matrix1, target1))  # Expected output: True

    # case 2
    matrix2 = [[1,3,5,7], [10,11,16,20], [23,30,34,60]]
    target2 = 13
    print(solution.searchMatrix(matrix2, target2))  # Expected output: False

    # Additional case: Empty matrix
    matrix3 = []
    target3 = 3
    print(solution.searchMatrix(matrix3, target3))  # Expected output: False
