class Solution:
    def continuousSubarrays(self, nums):
        n = len(nums)
        left = 0
        total_count = 0
        min_queue, max_queue = [], []

        for right in range(n):
            while min_queue and nums[min_queue[-1]] >= nums[right]:
                min_queue.pop()
            while max_queue and nums[max_queue[-1]] <= nums[right]:
                max_queue.pop()

            min_queue.append(right)
            max_queue.append(right)

            while nums[max_queue[0]] - nums[min_queue[0]] > 2:
                if min_queue[0] == left:
                    min_queue.pop(0)
                if max_queue[0] == left:
                    max_queue.pop(0)
                left += 1

            total_count += right - left + 1

        return total_count

# Test cases
if __name__ == "__main__":
    solution = Solution()
    # case 1
    nums1 = [5, 4, 2, 4]
    print("Output:", solution.continuousSubarrays(nums1))  # Expected output: 8
    # case 2
    nums2 = [1, 2, 3]
    print("Output:", solution.continuousSubarrays(nums2))  # Expected output: 6
