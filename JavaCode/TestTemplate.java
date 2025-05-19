package JavaCode;

public class TestTemplate {
    public static void main(String[] args) {
        TypeOfTriangle solver = new TypeOfTriangle();

        // case 1
        int[] nums1 = {3, 3, 3};
        System.out.println("Result of test case 1: " + solver.triangleType(nums1)); // Output: equilateral

        // case 2
        int[] nums2 = {3, 4, 5};
        System.out.println("Result of test case 2: " + solver.triangleType(nums2)); // Output: scalene
    }
}

