class Solution:
    def maxProfit(self, prices, fee):
        cash, hold = 0, float('-inf')
        
        for price in prices:
            cash = max(cash, hold + price - fee)
            hold = max(hold, cash - price)
        
        return cash

# Test cases
if __name__ == "__main__":
    sol = Solution()
    
    prices1 = [1, 3, 2, 8, 4, 9]
    fee1 = 2
    result1 = sol.maxProfit(prices1, fee1)
    print(f"Output 1: {result1}")
    
    prices2 = [1, 3, 7, 5, 10, 3]
    fee2 = 3
    result2 = sol.maxProfit(prices2, fee2)
    print(f"Output 2: {result2}")