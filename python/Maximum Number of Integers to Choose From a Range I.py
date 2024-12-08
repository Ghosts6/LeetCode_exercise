class Solution:
    def maxCount(self, banned, n, maxSum):
        banned_set = set(banned)
        total_sum = 0
        count = 0
        
        for i in range(1, n + 1):
            if i in banned_set:
                continue
            if total_sum + i > maxSum:
                break
            total_sum += i
            count += 1
        
        return count
# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # case 1
    print("Test case 1 output:", solution.maxCount([1, 6, 5], 5, 6)) # Expected output: 2
    
    # case 2
    print("Test case 2 output:", solution.maxCount([1, 2, 3, 4, 5, 6, 7], 8, 1)) # Expected output: 0
    
    # case 3
    print("Test case 3 output:", solution.maxCount([11], 7, 50)) # Expected output: 7 