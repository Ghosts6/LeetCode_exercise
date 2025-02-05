class Solution:
    def areAlmostEqual(self, s1:str, s2:str) -> bool:
        diff = [(a, b) for a, b in zip(s1, s2) if a != b]
        return not diff or len(diff) == 2 and diff[0] == diff[1][::-1]
# Test cases
if __name__ == "__main__":
    solution = Solution()
    # case 1
    s1_1 = "bank"
    s1_2 = "kanb"
    print("Result of test case 1:", solution.areAlmostEqual(s1_1, s1_2)) # Expected Output: true
    # case 2
    s2_1 = "attack"
    s2_2 = "defend"
    print("Result of test case 1:", solution.areAlmostEqual(s2_1, s2_2)) # Expected Output: false
    # case 3
    s3_1 = "kelb"
    s3_2 = "kelb"
    print("Result of test case 1:", solution.areAlmostEqual(s3_1, s3_2)) # Expected Output: true