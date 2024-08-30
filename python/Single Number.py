class Solution:
    def singleNumber(self, nums):
        result = 0
        for num in nums:
            result ^= num
        return result
    
# Test case
solution = Solution()
test_case = [4, 1, 2, 1, 2]
output = solution.singleNumber(test_case)
print(f"The single number in {test_case} is: {output}")
