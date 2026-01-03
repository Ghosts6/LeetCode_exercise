from typing import List

class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        """Return all unique subsets using a backtracking approach with pruning."""
        nums.sort()
        res = []
        
        def backtrack(start: int, path: List[int]):
            res.append(list(path))
            for i in range(start, len(nums)):
                if i > start and nums[i] == nums[i - 1]:
                    continue
                path.append(nums[i])
                backtrack(i + 1, path)
                path.pop()
        
        backtrack(0, [])
        return res

# Test cases
if __name__ == "__main__":
    sol = Solution()

    # case 1
    nums1 = [1, 2, 2]
    print(f"Result of test case 1: {sol.subsetsWithDup(nums1)}") 

    # case 2
    nums2 = [0]
    print(f"Result of test case 2: {sol.subsetsWithDup(nums2)}")
