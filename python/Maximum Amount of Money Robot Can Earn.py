from typing import List

class Solution:
    def maximumAmount(self, coins: List[List[int]]) -> int:
        """DP with up to 2 neutralizations, O(n) space."""
        m, n = len(coins), len(coins[0])
        INF = float('-inf')
        
        prev = [[INF]*3 for _ in range(n)]
        
        for i in range(m):
            curr = [[INF]*3 for _ in range(n)]
            for j in range(n):
                val = coins[i][j]
                
                for k in range(3):
                    if i == 0 and j == 0:
                        if val >= 0:
                            curr[j][k] = val
                        else:
                            curr[j][k] = 0 if k > 0 else val
                        continue
                    
                    # from top / left (same k)
                    best = INF
                    if i > 0:
                        best = max(best, prev[j][k])
                    if j > 0:
                        best = max(best, curr[j-1][k])
                    
                    if best != INF:
                        curr[j][k] = max(curr[j][k], best + val)
                    
                    # use neutralization if negative
                    if val < 0 and k > 0:
                        best_prev = INF
                        if i > 0:
                            best_prev = max(best_prev, prev[j][k-1])
                        if j > 0:
                            best_prev = max(best_prev, curr[j-1][k-1])
                        
                        if best_prev != INF:
                            curr[j][k] = max(curr[j][k], best_prev)
            
            prev = curr
        
        return max(prev[n-1])

if __name__ == "__main__":
    sol = Solution()

    # case 1
    coins1 = [[0,1,-1],[1,-2,3],[2,-3,4]]
    print(f"Result of test case 1: {sol.maximumAmount(coins1)}") # Expected: 8

    # case 2
    coins2 = [[10,10,10],[10,10,10]]
    print(f"Result of test case 2: {sol.maximumAmount(coins2)}") # Expected: 40
