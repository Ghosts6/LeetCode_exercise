from typing import List
from collections import defaultdict

class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        
        count = defaultdict(int)
        operations = 0

        for num in nums:
            complement = k - num
            if count[complement] > 0:
                operations += 1
                count[complement] -= 1
            else:
                count[num] += 1

        return operations

# test case
if __name__ == "__main__":
    solution = Solution()
    nums = [1, 2, 3, 4]
    k = 5
    result = solution.maxOperations(nums, k)
    print(f"maximum number of operations: {result}")  