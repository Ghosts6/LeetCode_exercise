from typing import List

class Solution:
    def maxArea(self, height: List[int]) -> int:
        left, right = 0, len(height) - 1
        max_water = 0
        
        while left < right:
            width = right - left
            h = min(height[left], height[right])
            current_water = width * h
            max_water = max(max_water, current_water)
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        
        return max_water

# test case
if __name__ == "__main__":
    solution = Solution()
    
    # case 1
    height = [1,8,6,2,5,4,8,3,7]
    result = solution.maxArea(height)
    print(f"Maximum amount of water the container can store: {result}") 
