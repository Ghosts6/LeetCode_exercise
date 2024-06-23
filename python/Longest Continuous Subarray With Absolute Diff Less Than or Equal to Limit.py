from collections import deque

class Solution:
    def longestSubarray(self, nums, limit):
        max_deque = deque()
        min_deque = deque()
        left = 0
        max_length = 0

        for right in range(len(nums)):
            while max_deque and nums[right] > max_deque[-1]:
                max_deque.pop()
            while min_deque and nums[right] < min_deque[-1]:
                min_deque.pop()

            max_deque.append(nums[right])
            min_deque.append(nums[right])

            while max_deque[0] - min_deque[0] > limit:
                if nums[left] == max_deque[0]:
                    max_deque.popleft()
                if nums[left] == min_deque[0]:
                    min_deque.popleft()
                left += 1

            max_length = max(max_length, right - left + 1)

        return max_length

# test case
nums = [8, 2, 4, 7]
limit = 4
solution = Solution()
print(solution.longestSubarray(nums, limit))
