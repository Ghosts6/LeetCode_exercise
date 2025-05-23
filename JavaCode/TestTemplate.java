package JavaCode;

import java.util.Arrays;
import java.util.List;

public class TestTemplate {
    public static void main(String[] args) {
        LongestUnequalAdjacentGroupsSubsequenceI solver = new LongestUnequalAdjacentGroupsSubsequenceI();

        // case 1
        String[] words1 = {"e", "a", "b"};
        int[] groups1 = {0, 0, 1};
        List<String> result1 = solver.getLongestSubsequence(words1, groups1);
        System.out.println("Result of test case 1: " + result1); // Expected: [e, b]

        // case 2
        String[] words2 = {"a", "b", "c", "d"};
        int[] groups2 = {1, 0, 1, 1};
        List<String> result2 = solver.getLongestSubsequence(words2, groups2);
        System.out.println("Result of test case 2: " + result2); // Expected: [a, b, c]
    }
}

