public class FindKthBitInNthBinaryString {
    public static void main(String[] args) {
        Solution sol = new Solution();

        // case 1
        int n1 = 3;
        int k1 = 1;
        System.out.println("Result of test case 1 : " + sol.findKthBit(n1, k1)); // Expected "0"

        // case 2
        int n2 = 4;
        int k2 = 11;
        System.out.println("Result of test case 2 : " + sol.findKthBit(n2, k2)); // Expected "1"
    }
}

class Solution {

    public char findKthBit(int n, int k) {
        return find(n, k);
    }

    private char find(int n, int k) {
        if (n == 1) {
            return '0';
        }

        int mid = 1 << (n - 1);   // midpoint of current sequence

        if (k == mid) {
            return '1';
        }

        if (k < mid) {
            return find(n - 1, k);
        }

        // mirrored position
        int mirrored = (1 << n) - k;

        // invert the mirrored result
        return (char) (find(n - 1, mirrored) ^ 1);
    }
}
