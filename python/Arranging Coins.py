class Solution:
    def arrangeCoins(self, n: int) -> int:
        left, right = 0, n
        
        while left <= right:
            mid = (left + right) // 2
            total_coins = mid * (mid + 1) // 2
            
            if total_coins == n:
                return mid
            elif total_coins < n:
                left = mid + 1
            else:
                right = mid - 1
                
        return right  
# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # case 1
    n1 = 5
    result1 = solution.arrangeCoins(n1)
    print(f"Input: {n1}, Output: {result1} (Expected: 2)")

    # case 2
    n2 = 8
    result2 = solution.arrangeCoins(n2)
    print(f"Input: {n2}, Output: {result2} (Expected: 3)")
