class Solution:
    def countDigits(self, num: int) -> int:
        count = 0
        original_num = num
        
        while num > 0:
            digit = num % 10
            num //= 10
            
            # Avoid division by zero
            if digit != 0 and original_num % digit == 0:
                count += 1
        
        return count

# Test cases
if __name__ == "__main__":
    solution = Solution()
    print(solution.countDigits(7))   # Output: 1
    print(solution.countDigits(121)) # Output: 2
    print(solution.countDigits(1248)) # Output: 4

