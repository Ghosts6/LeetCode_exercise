package JavaCode;

// Test cases
public class CountSquareSumTriples {
	public static void main(String[] args) {
		Solution obj = new Solution();
		// case 1
		int n1 = 5;
		System.out.println("Result of test case 1 : " + obj.countTriples(n1)); // Expected: 2

		// case 2
		int n2 = 10;
		System.out.println("Result of test case 2 : " + obj.countTriples(n2)); // Expected: 4
	}	
}

public class Solution {
    public int countTriples(int n) {
        int maxSq = n * n;
        boolean[] isSquare = new boolean[maxSq + 1];
        for (int c = 1; c <= n; c++) {
            isSquare[c * c] = true;
        }

        int count = 0;

        for (int a = 1; a <= n; a++) {
            int a2 = a * a;
            for (int b = 1; b <= n; b++) {
                int sum = a2 + b * b;
                if (sum <= maxSq && isSquare[sum]) {
                    count++;
                }
            }
        }

        return count;
    }
}

