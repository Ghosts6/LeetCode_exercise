class Solution:
    def isPalindrome(self, x: int) -> bool:
        """
        Determine whether an integer is a palindrome without converting it to a string.
        """
        if x < 0:
            return False
        reversed_num = 0
        original = x
        while x > 0:
            reversed_num = reversed_num * 10 + x % 10
            x //= 10
        return original == reversed_num
# Test cases
if __name__ == "__main__":
    solution = Solution()
    # case 1
    x1 = 121
    print(f"result of test case 1 : {solution.isPalindrome(x1)}") # Expected Output: true

    # case 2
    x2 = -121
    print(f"result of test case 2 : {solution.isPalindrome(x2)}") # Expected Output: false

    # case 3
    x3 = 10
    print(f"result of test case3 : {solution.isPalindrome(x3)}") # Expected Output: false