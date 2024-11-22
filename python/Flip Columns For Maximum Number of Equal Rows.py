class Solution:
    def maxEqualRowsAfterFlips(self, matrix):
        signature_count = {}
        
        for row in matrix:
            signature = tuple(row if row[0] == 0 else [1 - x for x in row])
            
            if signature in signature_count:
                signature_count[signature] += 1
            else:
                signature_count[signature] = 1
        
        return max(signature_count.values())
# Test cases
if __name__=="__main__":
    solution = Solution()
    
    # =Case 1
    matrix1 = [[0, 1], [1, 1]]
    print(f"Test Case 1: {solution.maxEqualRowsAfterFlips(matrix1)}")  # Expected: 1
    
    # case 2
    matrix2 = [[0, 1], [1, 0]]
    print(f"Test Case 2: {solution.maxEqualRowsAfterFlips(matrix2)}")  # Expected: 2
    
    # Case 3
    matrix3 = [[0, 0, 0], [0, 0, 1], [1, 1, 0]]
    print(f"Test Case 3: {solution.maxEqualRowsAfterFlips(matrix3)}")  # Expected: 2
    
