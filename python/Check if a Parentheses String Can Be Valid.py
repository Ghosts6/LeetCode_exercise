class Solution:
    def canBeValid(self, s: str, locked: str) -> bool:
        if len(s) % 2 != 0:
            return False
        
        open_count = 0
        for i in range(len(s)):
            if locked[i] == '0' or s[i] == '(':
                open_count += 1
            else:
                open_count -= 1
            if open_count < 0:
                return False
        
        close_count = 0
        for i in range(len(s) - 1, -1, -1):
            if locked[i] == '0' or s[i] == ')':
                close_count += 1
            else:
                close_count -= 1
            if close_count < 0:
                return False
        
        return True

# Test cases
if __name__ == "__main__":
    solution = Solution()
    # case 1
    s1 = "()()"
    locked1 = "0100"
    print("Output of case 1 is", solution.canBeValid(s1, locked1)) # Expected Output: True
    # case 2
    s2 = ")"
    locked2 = "0"
    print("Output of case 2 is", solution.canBeValid(s2, locked2)) # Expected Output: False
