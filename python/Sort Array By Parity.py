from typing import List

class Solution:
    def sortArrayByParity(self, A: List[int]) -> List[int]:
        left, right = 0, len(A) - 1
        
        while left < right:
            if A[left] % 2 > A[right] % 2:
                A[left], A[right] = A[right], A[left]

            if A[left] % 2 == 0:
                left += 1
            if A[right] % 2 == 1:
                right -= 1
        
        return A
    
# Test cases
if __name__ == "__main__":
    solution = Solution()

    # case 1
    num1 = [3, 1 , 2, 4]
    print(f"result for {num1} is : {solution.sortArrayByParity(num1)}") # Expected output: [2,4,3,1]

    # case 2
    num2 = [0]
    print(f"result for {num2} is : {solution.sortArrayByParity(num2)}") # Expected output: [0]