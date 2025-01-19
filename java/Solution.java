package java;

// FindMinimumOperationsToMakeAllElementsDivisibleByThree
public class Solution {
    public int minimumOperations(int[] nums) {
        int operations = 0;

        for (int num : nums) {
            int remainder = num % 3;

            if (remainder != 0) {
                operations += Math.min(remainder, 3 - remainder);
            }
        }

        return operations;
    }

    // Test cases
    public static void main(String[] args) {
        Solution solution = new Solution();

        // case 1
        int[] nums1 = {1, 2, 3, 4};
        System.out.println("Minimum operations for nums1: " + solution.minimumOperations(nums1)); // Expected: 3

        // case 2
        int[] nums2 = {3, 6, 9};
        System.out.println("Minimum operations for nums2: " + solution.minimumOperations(nums2)); // Expected: 0

        // case 3
        int[] nums3 = {10, 11, 13};
        System.out.println("Minimum operations for nums3: " + solution.minimumOperations(nums3)); // Expected: 5
    }
}