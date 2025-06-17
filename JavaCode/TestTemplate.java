package JavaCode;

public class TestTemplate {
    public static void main(String[] args) {
        LongestConsecutiveSequence solver = new LongestConsecutiveSequence();

        int[] test1 = {100, 4, 200, 1, 3, 2};
        System.out.println("Result of test case 1: " + solver.longestConsecutive(test1)); // Expected: 4

        int[] test2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
        System.out.println("Result of test case 2: " + solver.longestConsecutive(test2)); // Expected: 9

        int[] test3 = {1, 0, 1, 2};
        System.out.println("Result of test case 3: " + solver.longestConsecutive(test3)); // Expected: 3
    }
}
