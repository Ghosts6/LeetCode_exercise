class Solution {
    public int countSquares(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int[] dp = new int[n + 1];
        int count = 0;
        int prev = 0;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int temp = dp[j];
                if (matrix[i - 1][j - 1] == 1) {
                    dp[j] = Math.min(Math.min(dp[j], dp[j - 1]), prev) + 1;
                    count += dp[j];
                } else {
                    dp[j] = 0;
                }
                prev = temp;
            }
        }

        return count;
    }
}