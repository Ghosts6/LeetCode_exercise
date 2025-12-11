package JavaCode;

import java.util.*;

// Test cases
public class CountCoveredBuildings {
    public static void main(String[] args) {
        Solution obj = new Solution();

        // case 1
        int n1 = 3;
        int buildings1[][] = {{1, 1}, {1, 2}, {2, 1}, {2, 2}};
        System.out.println("Result of test case 1 : " + obj.countCoveredBuildings(n1, buildings1)); // Expected: 0

        // case 2
        int n2 = 3;
        int buildings2[][] = {{1, 2}, {2, 2}, {3, 2}, {2, 1}, {2, 3}};
        System.out.println("Result of test case 2 : " + obj.countCoveredBuildings(n2, buildings2)); // Expected: 1

        // case 3
        int n3 = 3;
        int buildings3[][] = {{1, 1}, {1, 2}, {2, 1}, {2, 2}};
        System.out.println("Result of test case 3 : " + obj.countCoveredBuildings(n3, buildings3)); // Expected: 0
    }
}

class Solution {
    public int countCoveredBuildings(int n, int[][] buildings) {
        Map<Integer, int[]> row = new HashMap<>();
        Map<Integer, int[]> col = new HashMap<>();

        for (int[] b : buildings) {
            int x = b[0], y = b[1];

            row.computeIfAbsent(x, k -> new int[]{y, y});
            row.get(x)[0] = Math.min(row.get(x)[0], y);
            row.get(x)[1] = Math.max(row.get(x)[1], y);

            col.computeIfAbsent(y, k -> new int[]{x, x});
            col.get(y)[0] = Math.min(col.get(y)[0], x);
            col.get(y)[1] = Math.max(col.get(y)[1], x);
        }

        int count = 0;
        for (int[] b : buildings) {
            int x = b[0], y = b[1];

            int[] ry = row.get(x);
            int[] cx = col.get(y);

            if (ry[0] < y && y < ry[1] && cx[0] < x && x < cx[1]) {
                count++;
            }
        }
        return count;
    }
}
