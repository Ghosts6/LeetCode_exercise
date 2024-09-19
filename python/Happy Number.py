class Solution:
    def isHappy(self, n: int) -> bool:
        seen = set()
        
        def getSumOfSquares(num):
            total_sum = 0
            while num > 0:
                digit = num % 10
                total_sum += digit * digit
                num //= 10
            return total_sum

        while n != 1 and n not in seen:
            seen.add(n)
            n = getSumOfSquares(n)
        
        return n == 1

# Test case
if __name__ == "__main__":
    solution = Solution()
    n = 19
    result = solution.isHappy(n)
    print(f"{n} is a happy number: {result}")
