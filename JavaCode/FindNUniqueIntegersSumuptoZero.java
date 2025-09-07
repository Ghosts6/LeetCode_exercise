package JavaCode;

import java.util.Arrays;

/**
 * This class provides a solution for finding n unique integers that sum up to zero.
 */
public class FindNUniqueIntegersSumuptoZero {
    public static void main(String[] args) {
        Solution solver = new Solution();
	// Test cases
        // case 1
        int n1 = 5;
        System.out.println(Arrays.toString(solver.sumZero(n1))); // Expected [-7,-1,1,3,4]

        // case 2
        int n2 = 3;
        System.out.println(Arrays.toString(solver.sumZero(n2))); // Expected [-1,0,1]

        // case 3
        int n3 = 1;
        System.out.println(Arrays.toString(solver.sumZero(n3))); // Expected [0]
    }
}

/**
 * Given an integer n, return any array containing n unique integers such that they add up to 0.
 */
class Solution {
    /**
     * This method returns an array of n unique integers that sum up to 0.
     * @param n The number of unique integers.
     * @return An array of n unique integers that sum up to 0.
     */
    public int[] sumZero(int n) {
        int[] res = new int[n];
        int num = 1;
        for (int i = 0; i < n / 2; i++) {
            res[i] = num;
            res[n - 1 - i] = -num;
            num++;
        }
        if (n % 2 != 0) res[n / 2] = 0;
        return res;
    }
}

