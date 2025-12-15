package JavaCode;

// Test cases
public class NumberofSmoothDescentPeriodsofaStock {
    public static void main(String[] args) {
        Solution obj = new Solution();

        // case 1
        int[] prices1 = {3, 2, 1, 4};
        System.out.println("Result of test case 1 : " + obj.getDescentPeriods(prices1)); // Expected: 7

        // case 2
        int[] prices2 = {8, 6, 7, 7};
        System.out.println("Result of test case 2 : " + obj.getDescentPeriods(prices2)); // Expected: 4 

        // case 3
        int[] prices3 = {1};
        System.out.println("Result of test case 3 : " + obj.getDescentPeriods(prices3)); // Expected: 1
    }
}

class Solution {
    public long getDescentPeriods(int[] prices) {
        long totalPeriods = 0;
        int currentLength = 1;
        
        if (prices.length == 0) {
            return 0;
        }

        totalPeriods = 1;

        for (int i = 1; i < prices.length; i++) {
            
            if (prices[i] == prices[i - 1] - 1) {
                currentLength++;
            } else {
                currentLength = 1;
            }
            
            totalPeriods += currentLength;
        }

        return totalPeriods;
    }
}
