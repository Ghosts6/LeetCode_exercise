package JavaCode;

import java.util.Arrays;

public class TestTemplate {
    public static void main(String[] args) {
        DivideaStringIntoGroupsOfSizeK solver = new DivideaStringIntoGroupsOfSizeK();

        String s1 = "abcdefghi";
        int k1 = 3;
        char fill1 = 'x';
        System.out.println("Result of test case 1: " + Arrays.toString(solver.divideString(s1, k1, fill1)));
        // Expected: ["abc", "def", "ghi"]

        String s2 = "abcdefghij";
        int k2 = 3;
        char fill2 = 'x';
        System.out.println("Result of test case 2: " + Arrays.toString(solver.divideString(s2, k2, fill2)));
        // Expected: ["abc", "def", "ghi", "jxx"]
    }
}

