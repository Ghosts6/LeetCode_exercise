package JavaCode;

public class TestTemplate {
    public static void main(String[] args) {
        MinimumEqualSumofTwoArraysAfterReplacingZeros solver = new MinimumEqualSumofTwoArraysAfterReplacingZeros();

        int[] nums1_1 = {3, 2, 0, 1, 0};
        int[] nums2_1 = {6, 5, 0};
        System.out.println(solver.minSum(nums1_1, nums2_1)); // Output: 12

        int[] nums1_2 = {2, 0, 2, 0};
        int[] nums2_2 = {1, 4};
        System.out.println(solver.minSum(nums1_2, nums2_2)); // Output: -1
    }  
}

