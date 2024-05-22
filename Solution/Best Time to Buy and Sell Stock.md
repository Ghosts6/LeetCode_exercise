# -Best Time to Buy and Sell Stock

# 📋 Problem Description
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

# 💡 Intuition
The problem is to find the maximum profit that can be achieved by buying and then selling one share of stock. To solve this problem, we need to find two specific days: one to buy and one to sell, such that the selling price is higher than the buying price and the profit is maximized.

# 🛠️ Approach
1.  Initialization: Start by initializing the minimum price to the first price in the list and the maximum profit to 0.
2.  Iterate through prices: For each price:
    If the current price is less than the minimum price seen so far, update the minimum price.
    Otherwise, calculate the profit by subtracting the current minimum price from the current price and update the maximum profit if this profit is higher than the previously recorded maximum profit.
3.  Return the maximum profit: After iterating through all prices, the maximum profit recorded will be the answer.

# 🧮 Complexity
- Time complexity:
O(n), where n is the number of prices. We only make one pass through the list.

- Space complexity:
O(1), as we are using only a constant amount of additional space.

# 💻 Code
### c++
```cpp
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.empty()) return 0;

        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } else {
                maxProfit = std::max(maxProfit, prices[i] - minPrice);
            }
        }

        return maxProfit;
    }
};
```
### python
```py
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0

        min_price = prices[0]
        max_profit = 0

        for price in prices[1:]:
            if price < min_price:
                min_price = price
            else:
                max_profit = max(max_profit, price - min_price)

        return max_profit
```
### java script
```js
var maxProfit = function(prices) {
    if (prices.length === 0) return 0;

    let minPrice = prices[0];
    let maxProfit = 0;

    for (let i = 1; i < prices.length; ++i) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else {
            maxProfit = Math.max(maxProfit, prices[i] - minPrice);
        }
    }

    return maxProfit;
};
```
