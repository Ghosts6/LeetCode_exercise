package JavaCode;

public class TypeOfTriangle {
      public String triangleType(int[] nums) {
        if (nums == null || nums.length != 3) {
            throw new IllegalArgumentException("Array must contain exactly 3 elements.");
        }

        int a = nums[0], b = nums[1], c = nums[2];

        if (a + b <= c || a + c <= b || b + c <= a) {
            return "none"; 
        }

        if (a == b && b == c) {
            return "equilateral";
        } else if (a == b || b == c || a == c) {
            return "isosceles";
        } else {
            return "scalene";
        }
    }
}
