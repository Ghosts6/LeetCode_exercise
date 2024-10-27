class Solution:
    def lengthOfLIS(self, nums):
        if not nums:
            return 0
        lis = []

        def binary_search(arr, target):
            left, right = 0, len(arr) - 1
            while left <= right:
                mid = (left + right) // 2
                if arr[mid] < target:
                    left = mid + 1
                else:
                    right = mid - 1
            return left  

        for num in nums:
            pos = binary_search(lis, num)

            if pos == len(lis):
                lis.append(num)
            else:
                lis[pos] = num  

        return len(lis)

# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # case 1
    nums1 = [10, 9, 2, 5, 3, 7, 101, 18]
    print("Output for Test Case 1:", solution.lengthOfLIS(nums1))  # Expected output: 4
    
    # case 2
    nums2 = [0, 1, 0, 3, 2, 3]
    print("Output for Test Case 2:", solution.lengthOfLIS(nums2))  # Expected output: 4
    
    # case 3
    nums3 = [7, 7, 7, 7, 7, 7, 7]
    print("Output for Test Case 3:", solution.lengthOfLIS(nums3))  # Expected output: 1
