package JavaCode;

public class TestTemplate {
    public static void main(String[] args) {
        MaximumDifferenceByRemappingADigit solver = new MaximumDifferenceByRemappingADigit();

        int n1 = 11891;
        System.out.println("result of test case 1: " + solver.minMaxDifference(n1)); // Expected: 99009

        int n2 = 90;
        System.out.println("result of test case 2: " + solver.minMaxDifference(n2)); // Expected: 99
    }
}
