class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        if num == 1:
            return True
        
        left, right = 1, num // 2
        
        while left <= right:
            mid = left + (right - left) // 2
            square = mid * mid
            
            if square == num:
                return True
            elif square < num:
                left = mid + 1
            else:
                right = mid - 1
        
        return False

# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    #  case 1
    num1 = 16
    print(f"Input: {num1} - Output: {solution.isPerfectSquare(num1)}")  # Expected: True
    
    # case 2
    num2 = 14
    print(f"Input: {num2} - Output: {solution.isPerfectSquare(num2)}")  # Expected: False

    # additional case
    num3 = 1
    print(f"Input: {num3} - Output: {solution.isPerfectSquare(num3)}")  # Expected: True