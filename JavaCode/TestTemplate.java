package JavaCode;

public class TestTemplate {
    public static void main(String[] args) {
        DivisibleAndNondivisibleSumsDifference solver = new DivisibleAndNondivisibleSumsDifference();

        // Case 1
        int n1 = 10, m1 = 3;
        System.out.println("differenceOfSums example 1: " + solver.differenceOfSums(n1, m1)); // Expected: 19

        // Case 2
        int n2 = 5, m2 = 6;
        System.out.println("differenceOfSums example 2: " + solver.differenceOfSums(n2, m2)); // Expected: 15

        // Case 3
        int n3 = 5, m3 = 1;
        System.out.println("differenceOfSums example 3: " + solver.differenceOfSums(n3, m3)); // Expected: -15
    }
}