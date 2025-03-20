class Solution:
    def findContentChildren(self, g: list[int], s: list[int]) -> int:
        """Maximizes the number of content children given greed factors and cookie sizes."""
        g.sort()
        s.sort()
        i = j = 0
        while i < len(g) and j < len(s):
            if s[j] >= g[i]:
                i += 1
            j += 1
        return i

# Test cases
if __name__ == "__main__":
    solution = Solution()

    # Case 1
    g1 = [1,2,3]
    s1 = [1,1]
    print(f"result of test case 1 : {solution.findContentChildren(g1, s1)}") # Expected Output: 1

    # Case 2
    g2 = [1,2]
    s2 = [1,2,3]
    print(f"result of test case 2 : {solution.findContentChildren(g2, s2)}") # Expected Output: 2