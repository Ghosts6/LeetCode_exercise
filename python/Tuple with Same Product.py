class Solution:
    def tupleSameProduct(self, nums):
        product_count = {}
        n = len(nums)
        
        for i in range(n):
            for j in range(i + 1, n):
                product = nums[i] * nums[j]
                if product in product_count:
                    product_count[product] += 1
                else:
                    product_count[product] = 1
        
        result = 0
        for count in product_count.values():
            if count > 1:
                result += count * (count - 1) * 4
        
        return result
# Test cases
if __name__ == "__main__":
    test_cases = [
        ([2, 3, 4, 6], 8),
        ([1, 2, 4, 5, 10], 16),
        ([1, 2, 3], 0),
        ([2, 4, 8, 16], 8),
    ]
    
    solution = Solution()
    for nums, expected in test_cases:
        result = solution.tupleSameProduct(nums)
        assert result == expected, f"Failed for {nums}: expected {expected}, got {result}"
    print("All test cases passed.")
