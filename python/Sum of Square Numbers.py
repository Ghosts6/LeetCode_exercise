import math

class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        if c < 0:
            return False
        
        left = 0
        right = int(math.sqrt(c))
        
        while left <= right:
            sum = left * left + right * right
            if sum == c:
                return True
            elif sum < c:
                left += 1
            else:
                right -= 1
                
        return False

#  test case
sol = Solution()
c = 5
result = sol.judgeSquareSum(c)
print(result) 
