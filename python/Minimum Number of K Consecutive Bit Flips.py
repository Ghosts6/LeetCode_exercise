from typing import List

class Solution:
    def minKBitFlips(self, nums: List[int], k: int) -> int:
        n = len(nums)
        flip_count = 0
        flipped = [0] * n
        flips = 0
        
        for i in range(n):
            if i >= k:
                flips ^= flipped[i - k]
            if nums[i] == flips:
                if i + k > n:
                    return -1
                flipped[i] = 1
                flips ^= 1
                flip_count += 1
        
        return flip_count

# test case
if __name__ == "__main__":
    solution = Solution()
    
    nums = [0, 1, 0]
    k = 1
    result = solution.minKBitFlips(nums, k)
    
    print("result of test case :", result)  
