from typing import List

class Solution:
    def minimumPairRemoval(self, nums: List[int]) -> int:
        """Return minimum operations to make array non-decreasing"""
        def is_non_decreasing(arr):
            return all(arr[i] >= arr[i - 1] for i in range(1, len(arr)))

        ops = 0
        arr = nums[:]

        while not is_non_decreasing(arr):
            min_sum = float('inf')
            idx = 0
            for i in range(len(arr) - 1):
                s = arr[i] + arr[i + 1]
                if s < min_sum:
                    min_sum = s
                    idx = i
            arr = arr[:idx] + [arr[idx] + arr[idx + 1]] + arr[idx + 2:]
            ops += 1

        return ops

# Test case
if __name__ == "__main__":
    sol = Solution()

    # case 1
    print(f"Result of test case 1 : {sol.minimumPairRemoval([5, 2, 3, 1])}") # Expected 2

    # case 2
    print(f"Result of test case 2 : {sol.minimumPairRemoval([1, 2, 2])}") # Expected 0
