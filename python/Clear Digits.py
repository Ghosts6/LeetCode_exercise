class Solution:
    def clearDigits(self, s: str) -> str:
        stack = []
        for c in s:
            if c.isdigit():
                if stack:
                    stack.pop()
            else:
                stack.append(c)
        return "".join(stack)

# Test cases
if __name__ == "__main__":
    solution = Solution()
    # case 1
    s1 = "abc"
    print(f"Output of test case1 : {solution.clearDigits(s1)}") # Expected Output: "abc"
    # case 2
    s2 = "cb34"
    print(f"Output of test case2 : {solution.clearDigits(s2)}") # Expected Output: ""