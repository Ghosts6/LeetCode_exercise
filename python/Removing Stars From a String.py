class Solution:
    def removeStars(self, s: str) -> str:
        stack = []
        for char in s:
            if char == '*':
                if stack:
                    stack.pop()
            else:
                stack.append(char)
        return ''.join(stack)

# rest case
if __name__ == "__main__":
    solution = Solution()
    test_string = "ab*c*d"
    print("Result :", solution.removeStars(test_string))  
