class Solution:
    def maxSumOfThreeSubarrays(self, nums, k):
        n = len(nums)

        window_sum = sum(nums[:k])
        window_sums = [window_sum]  

        for i in range(1, n - k + 1):
            window_sum += nums[i + k - 1] - nums[i - 1]
            window_sums.append(window_sum)

        best_left = [0] * len(window_sums)
        best_idx = 0
        for i in range(len(window_sums)):
            if window_sums[i] > window_sums[best_idx]:
                best_idx = i
            best_left[i] = best_idx

        best_right = [0] * len(window_sums)
        best_idx = len(window_sums) - 1
        for i in range(len(window_sums) - 1, -1, -1):
            if window_sums[i] >= window_sums[best_idx]:
                best_idx = i
            best_right[i] = best_idx

        max_sum = 0
        result = [-1, -1, -1]
        for j in range(k, len(window_sums) - k):
            left_idx = best_left[j - k]
            right_idx = best_right[j + k]
            total_sum = window_sums[left_idx] + window_sums[j] + window_sums[right_idx]
            if total_sum > max_sum:
                max_sum = total_sum
                result = [left_idx, j, right_idx]

        return result
#  Test cases
if __name__ == "__main__":
    solution = Solution()
    # case 1
    nums = [1, 2, 1, 2, 6, 7, 5, 1]
    k = 2
    print(solution.maxSumOfThreeSubarrays(nums, k))  # Output: [0, 3, 5]

    # case 2
    nums = [1, 2, 1, 2, 1, 2, 1, 2, 1]
    k = 2
    print(solution.maxSumOfThreeSubarrays(nums, k))  # Output: [0, 2, 4]