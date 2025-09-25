package JavaCode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Triangle {
    public static void main(String[] args) {
        Solution obj = new Solution();

        List<List<Integer>> triangle = Arrays.asList(
            Arrays.asList(2),
            Arrays.asList(3, 4),
            Arrays.asList(6, 5, 7),
            Arrays.asList(4, 1, 8, 3)
        );
        System.out.println("Result of test case 1 : " + obj.minimumTotal(triangle)); // Expected 11

        List<List<Integer>> triangle2 = Arrays.asList(
            Arrays.asList(-10)
        );
        System.out.println("Result of test case 2 : " + obj.minimumTotal(triangle2)); // Expected -10
    }
}

class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();
        int[] dp = new int[n];
        for (int i = 0; i < n; i++) dp[i] = triangle.get(n - 1).get(i);
        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) {
                dp[col] = triangle.get(row).get(col) + Math.min(dp[col], dp[col + 1]);
            }
        }
        return dp[0];
    }
}

