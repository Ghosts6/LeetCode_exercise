class Solution:
    def minimumSubarrayLength(self, nums, k):
        prev = {}
        min_length = float('inf')
        
        for num in nums:
            new_prev = {}

            for or_val, length in prev.items():
                new_or = or_val | num
                new_length = length + 1
                if new_or not in new_prev or new_length < new_prev[new_or]:
                    new_prev[new_or] = new_length

            if num not in new_prev or 1 < new_prev[num]:
                new_prev[num] = 1

            for or_val, length in new_prev.items():
                if or_val >= k:
                    if length < min_length:
                        min_length = length

            prev = new_prev
        
        return min_length if min_length != float('inf') else -1
# Test cases
if __name__=="__main__":
    solution = Solution()
    # case 1
    nums1 = [1, 2, 3]
    k1 = 2
    print("Output:", solution.minimumSubarrayLength(nums1, k1))  # Expected output: 1
    # case 2
    nums2 = [2, 1, 8]
    k2 = 10
    print("Output:", solution.minimumSubarrayLength(nums2, k2))  # Expected output: 3
    # case 3
    nums3 = [1, 2]
    k3 = 0
    print("Output:", solution.minimumSubarrayLength(nums3, k3))  # Expected output: 1


