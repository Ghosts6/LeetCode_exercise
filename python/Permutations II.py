
from collections import Counter
from typing import List

class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        """Generate all unique permutations using backtracking."""
        result = []
        count = Counter(nums)
        path = []

        def backtrack():
            if len(path) == len(nums):
                result.append(path.copy())
                return

            for num in count:
                if count[num] == 0:
                    continue

                count[num] -= 1
                path.append(num)

                backtrack()

                path.pop()
                count[num] += 1

        backtrack()
        return result

# Test case
if __name__ == "__main__":
    sol = Solution()

    # case 1
    nums1 = [1, 1, 2]
    print(f"Result of test case 1 : {sol.permuteUnique(nums1)}") # Expected: [1,1,2],[1,2,1],[2,1,1]]

    # case 2
    nums2 = [1, 2, 3]
    print(f"Result of test case 2 : {sol.permuteUnique(nums2)}") # Expected: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

