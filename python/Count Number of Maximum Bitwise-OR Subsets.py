from typing import List

class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        max_or = 0
        for num in nums:
            max_or |= num  # Calculate the maximum possible OR
        
        self.count = 0
        
        def dfs(index: int, curr_or: int):
            if index == len(nums):
                if curr_or == max_or:
                    self.count += 1
                return
            # Include current number
            dfs(index + 1, curr_or | nums[index])
            # Exclude current number
            dfs(index + 1, curr_or)
        
        dfs(0, 0)
        return self.count

# Test case
if __name__ == "__main__":
    sol = Solution();

    # case 1
    nums1 = [2, 2, 2]
    print(f"Result of test case 1 : {sol.countMaxOrSubsets(nums1)}") # Expected: 7

    # case 2
    nums2 = [3, 1]
    print(f"Result of test case 2 : {sol.countMaxOrSubsets(nums2)}") # Expected: 2

    # case 3
    nums3 = [3, 2, 1, 5]
    print(f"Result of test case 3 : {sol.countMaxOrSubsets(nums3)}") # Expected: 6
