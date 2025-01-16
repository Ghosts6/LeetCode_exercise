class Solution:
    def xorAllNums(self, nums1, nums2):
        xor1, xor2 = 0, 0
        for num in nums1:
            xor1 ^= num
        for num in nums2:
            xor2 ^= num

        return (xor1 if len(nums2) % 2 else 0) ^ (xor2 if len(nums1) % 2 else 0)


# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # case 1
    nums1 = [2, 1, 3]
    nums2 = [10, 2, 5, 0]
    print(solution.xorAllNums(nums1, nums2))  # Output: 13

    # case 2
    nums1 = [1, 2]
    nums2 = [3, 4]
    print(solution.xorAllNums(nums1, nums2))  # Output: 0
