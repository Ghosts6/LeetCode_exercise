from typing import List

class Solution:
    def maximumSum(self, nums: List[int]) ->int:
        def digit_sum(n):
            return sum(int(d) for d in str(n))
        
        digit_map = {}
        max_sum = -1 
        
        for num in nums:
            s = digit_sum(num)
            if s in digit_map:
                max_sum = max(max_sum, num + digit_map[s])
                digit_map[s] = max(digit_map[s], num)
            else:
                digit_map[s] = num
            
        return max_sum

# Test case
if __name__ == "__main__":
    solution = Solution()
    # case 1
    nums_1 = [18,43,36,13,7]
    print(f"Out put of test case 1: {solution.maximumSum(nums_1)}") # Expected Output: 54

    # case 2
    nums_2 = [10,12,19,14]
    print(f"Out put of test case 2: {solution.maximumSum(nums_2)}") # Expected Output: -1
