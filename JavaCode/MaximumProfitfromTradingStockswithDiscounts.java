package JavaCode;

import java.util.*;

// Test case 
public class MaximumProfitfromTradingStockswithDiscounts {
    public static void main(String[] args) {
        Solution obj = new Solution();

        // case 1
        int n1 = 2; 
        int[] present1 = {1, 2};
        int[] future1 = {4, 3};
        int[][] hierarchy1 = {{1, 2}}; 
        int budget1 = 3;
        
        int result1 = obj.maxProfit(n1, present1, future1, hierarchy1, budget1);
        System.out.println("Result of test case 1: " + result1 + " (Expected: 5)");

        // case 2
        int n2 = 2; 
        int[] present2 = {3, 4};
        int[] future2 = {5, 8};
        int[][] hierarchy2 = {{1, 2}}; 
        int budget2 = 4;
        
        int result2 = obj.maxProfit(n2, present2, future2, hierarchy2, budget2);
        System.out.println("Result of test case 2: " + result2 + " (Expected: 4)");

        // case 3
        int n3 = 3; 
        int[] present3 = {4, 6, 8};
        int[] future3 = {7, 9, 11};
        int[][] hierarchy3 = {{1, 2}, {1, 3}}; 
        int budget3 = 10;
        
        int result3 = obj.maxProfit(n3, present3, future3, hierarchy3, budget3);
        System.out.println("Result of test case 3: " + result3 + " (Expected: 10)");

        // case 4
        int n4 = 3; 
        int[] present4 = {5, 2, 3};
        int[] future4 = {8, 5, 6};
        int[][] hierarchy4 = {{1, 2}, {2, 3}}; 
        int budget4 = 7;
        
        int result4 = obj.maxProfit(n4, present4, future4, hierarchy4, budget4);
        System.out.println("Result of test case 4: " + result4 + " (Expected: 12)");
    }
}

class Solution {
    private List<Integer>[] children;
    private int[] present;
    private int[] future;
    private int budget;
    private int n;
    private int[][][] dp;  // dp[u][c][s] - max profit in subtree of u with cost c, s=0: parent not bought, s=1: parent bought
    private static final int NEG_INF = Integer.MIN_VALUE / 2;

    public int maxProfit(int n, int[] present, int[] future, int[][] hierarchy, int budget) {
        this.n = n;
        this.present = present;
        this.future = future;
        this.budget = budget;
        
        // Build tree structure
        children = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            children[i] = new ArrayList<>();
        }
        
        for (int[] edge : hierarchy) {
            int u = edge[0] - 1;  // Convert to 0-based
            int v = edge[1] - 1;
            children[u].add(v);
        }
        
        // Initialize DP array
        dp = new int[n][budget + 1][2];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= budget; j++) {
                dp[i][j][0] = dp[i][j][1] = NEG_INF;
            }
        }
        
        dfs(0);
        
        // Answer is max profit from root with parent not bought (s=0)
        int maxProfit = 0;
        for (int c = 0; c <= budget; c++) {
            maxProfit = Math.max(maxProfit, dp[0][c][0]);
        }
        return maxProfit;
    }
    
    private void dfs(int u) {
        // Initialize arrays for this node
        int[] notBuy = new int[budget + 1];  // Don't buy current node
        int[] buyWithDiscount = new int[budget + 1];  // Buy with discount (if parent bought)
        int[] buyWithoutDiscount = new int[budget + 1];  // Buy without discount
        
        Arrays.fill(notBuy, NEG_INF);
        Arrays.fill(buyWithDiscount, NEG_INF);
        Arrays.fill(buyWithoutDiscount, NEG_INF);
        
        notBuy[0] = 0;  // Not buying costs nothing
        
        // Buying without discount (parent not bought)
        int costWithoutDiscount = present[u];
        int profitWithoutDiscount = future[u] - costWithoutDiscount;
        if (costWithoutDiscount <= budget) {
            buyWithoutDiscount[costWithoutDiscount] = profitWithoutDiscount;
        }
        
        // Buying with discount (parent bought)
        int costWithDiscount = present[u] / 2;
        int profitWithDiscount = future[u] - costWithDiscount;
        if (costWithDiscount <= budget) {
            buyWithDiscount[costWithDiscount] = profitWithDiscount;
        }
        
        // Process children
        for (int v : children[u]) {
            dfs(v);
            
            // Temporary arrays for merging
            int[] newNotBuy = new int[budget + 1];
            int[] newBuyWithDiscount = new int[budget + 1];
            int[] newBuyWithoutDiscount = new int[budget + 1];
            Arrays.fill(newNotBuy, NEG_INF);
            Arrays.fill(newBuyWithDiscount, NEG_INF);
            Arrays.fill(newBuyWithoutDiscount, NEG_INF);
            
            // Merge child's DP
            for (int c1 = 0; c1 <= budget; c1++) {
                if (notBuy[c1] == NEG_INF) continue;
                for (int c2 = 0; c1 + c2 <= budget; c2++) {
                    // When not buying current node, children see parent not bought (use dp[v][c2][0])
                    if (dp[v][c2][0] != NEG_INF) {
                        newNotBuy[c1 + c2] = Math.max(newNotBuy[c1 + c2], notBuy[c1] + dp[v][c2][0]);
                    }
                }
            }
            
            for (int c1 = 0; c1 <= budget; c1++) {
                if (buyWithoutDiscount[c1] == NEG_INF) continue;
                for (int c2 = 0; c1 + c2 <= budget; c2++) {
                    // When buying current node without discount, children see parent bought (use dp[v][c2][1])
                    if (dp[v][c2][1] != NEG_INF) {
                        newBuyWithoutDiscount[c1 + c2] = Math.max(
                            newBuyWithoutDiscount[c1 + c2], 
                            buyWithoutDiscount[c1] + dp[v][c2][1]
                        );
                    }
                }
            }
            
            for (int c1 = 0; c1 <= budget; c1++) {
                if (buyWithDiscount[c1] == NEG_INF) continue;
                for (int c2 = 0; c1 + c2 <= budget; c2++) {
                    // When buying current node with discount, children see parent bought (use dp[v][c2][1])
                    if (dp[v][c2][1] != NEG_INF) {
                        newBuyWithDiscount[c1 + c2] = Math.max(
                            newBuyWithDiscount[c1 + c2], 
                            buyWithDiscount[c1] + dp[v][c2][1]
                        );
                    }
                }
            }
            
            // Update arrays
            notBuy = newNotBuy;
            buyWithoutDiscount = newBuyWithoutDiscount;
            buyWithDiscount = newBuyWithDiscount;
        }
        
        // Set the final DP values for this node
        for (int c = 0; c <= budget; c++) {
            // For state where parent is not bought (s=0)
            dp[u][c][0] = Math.max(notBuy[c], buyWithoutDiscount[c]);
            // For state where parent is bought (s=1)
            dp[u][c][1] = Math.max(notBuy[c], buyWithDiscount[c]);
        }
    }
}