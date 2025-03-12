from typing import List

class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        """
        Returns the maximum count of positive integers and negative integers in the list.
        Approach:
        - Initialize positive_count and negative_count to 0.
        - Iterate through the list of numbers.
        - If the number is positive, increment positive_count by 1.
        - If the number is negative, increment negative_count by 1.
        - Return the maximum of positive_count and negative_count
        """
        positive_count = 0
        negative_count = 0

        for num in nums:
            if num > 0:
                positive_count += 1
            elif num < 0:
                negative_count += 1

        return max(positive_count, negative_count)

# Test case
if __name__ == "__main__":
    solution = Solution()

    # Test case 1
    nums_1 = [-3,-2,-1,0,0,1,2]
    print(f"Test case 1: {solution.maximumCount(nums_1)}") # Expected Output: 3

    # Test case 2
    nums_2 = [5,20,66,1314]
    print(f"Test case 2: {solution.maximumCount(nums_2)}") # Expected Output: 4