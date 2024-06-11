from typing import List

class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        if len(nums) < 3:
            return False

        first = second = float('inf')
        
        for num in nums:
            if num <= first:
                first = num  
            elif num <= second:
                second = num  
            else:
                return True
        
        return False

# test case
if __name__ == "__main__":
    solution = Solution()
    
    test_cases = [
        ([1, 2, 3, 4, 5], True),
        ([5, 4, 3, 2, 1], False),
    ]
    
    for nums, expected in test_cases:
        result = solution.increasingTriplet(nums)
        print(f"nums: {nums}, expected: {expected}, result: {result}")
