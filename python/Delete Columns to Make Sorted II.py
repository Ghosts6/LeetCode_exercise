from typing import List

class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        """Returns the minimum column deletions needed to make rows lexicographically sorted using a boolean prefix tracker."""
        res, n, m, is_sorted = 0, len(strs), len(strs[0]), [False] * (len(strs) - 1)
        for j in range(m):
            if all(is_sorted[i] or strs[i][j] <= strs[i+1][j] for i in range(n - 1)):
                for i in range(n - 1):
                    if strs[i][j] < strs[i+1][j]: is_sorted[i] = True
                if all(is_sorted): break
            else: res += 1
        return res

# Test cases
if __name__ == "__main__":
    sol = Solution()

    # case 1
    strs1 = ["ca", "bb", "ac"]
    print(f"Result of test case 1 : {sol.minDeletionSize(strs1)}") # Expected: 1

    # case 2
    strs2 = ["xc", "yb", "za"]
    print(f"Result of test case 2 : {sol.minDeletionSize(strs2)}") # Expected: 0

    # case 3
    strs3 = ["zyx", "wvu", "tsr"]
    print(f"Result of test case 3 : {sol.minDeletionSize(strs3)}") # Expected: 3
