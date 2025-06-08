package JavaCode;

public class TestTemplate {
    public static void main(String[] args) {
        LexicographicalNumbers solver = new LexicographicalNumbers();

        // Case 1
        int n1 = 13;
        System.out.println("result of test case 1: " + solver.lexicalOrder(n1)); // Expected: [1,10,11,12,13,2,3,4,5,6,7,8,9]

        // Case 2
        int n2 = 2;
        System.out.println("result of test case 2: " + solver.lexicalOrder(n2)); // Expected: [1, 2]
    }
}