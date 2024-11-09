from typing import List

class Solution:
    def getMaximumXor(self, nums: List[int], maximumBit: int) -> List[int]:
        n = len(nums)
        totalXor = 0

        for num in nums:
            totalXor ^= num
        
        mask = (1 << maximumBit) - 1
        answer = [0] * n
 
        for i in range(n):
            answer[i] = totalXor ^ mask
            totalXor ^= nums[n - 1 - i]
        
        return answer

# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # case 1
    nums1 = [0, 1, 1, 3]
    maximumBit1 = 2
    result1 = solution.getMaximumXor(nums1, maximumBit1)
    print("Output for nums = [0,1,1,3], maximumBit = 2:", result1)
    
    # case 2
    nums2 = [2, 3, 4, 7]
    maximumBit2 = 3
    result2 = solution.getMaximumXor(nums2, maximumBit2)
    print("Output for nums = [2,3,4,7], maximumBit = 3:", result2)
    
    # case 3
    nums3 = [0, 1, 2, 2, 5, 7]
    maximumBit3 = 3
    result3 = solution.getMaximumXor(nums3, maximumBit3)
    print("Output for nums = [0,1,2,2,5,7], maximumBit = 3:", result3)