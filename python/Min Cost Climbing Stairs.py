class Solution:
    def minCostClimbingStairs(self, cost):
        n = len(cost)

        if n == 1:
            return cost[0]
        elif n == 2:
            return min(cost[0], cost[1])

        prev2 = cost[0]
        prev1 = cost[1]

        for i in range(2, n):
            current = cost[i] + min(prev1, prev2)
            prev2 = prev1
            prev1 = current

        return min(prev1, prev2)

# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Case 1
    cost1 = [10, 15, 20]
    print("Input:", cost1)
    print("Output:", solution.minCostClimbingStairs(cost1))  # Output: 15
    
    # Case 2
    cost2 = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
    print("Input:", cost2)
    print("Output:", solution.minCostClimbingStairs(cost2))  # Output: 6

