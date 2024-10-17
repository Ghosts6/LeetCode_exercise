class Solution:
    def maximumSwap(self, num: int) -> int:
        digits = list(str(num))
        
        last = {int(x): i for i, x in enumerate(digits)}

        for i, x in enumerate(digits):
            for d in range(9, int(x), -1):
                if last.get(d, -1) > i:
                    digits[i], digits[last[d]] = digits[last[d]], digits[i]
                    return int(''.join(digits))
  
        return num

# Test cases
if __name__ == "__main__":
    solution = Solution()
    # case 1
    num1 = 2736
    result1 = solution.maximumSwap(num1)
    print(f"Input: {num1} => Output: {result1}")  # Expected: 7236
    
    # case 2
    num2 = 9973
    result2 = solution.maximumSwap(num2)
    print(f"Input: {num2} => Output: {result2}")  # Expected: 9973

