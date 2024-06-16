from typing import List

class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        current_sum = sum(nums[:k])
        max_sum = current_sum

        for i in range(k, len(nums)):
            current_sum += nums[i] - nums[i - k]

            max_sum = max(max_sum, current_sum)

        return max_sum / k

# test case
if __name__ == "__main__":
    solution = Solution()

    nums = [1, 12, -5, -6, 50, 3]
    k = 4
    result = solution.findMaxAverage(nums, k)
    print(f"maximum average of subarray of length {k}: {result:.5f}") 
