package JavaCode;

import java.util.*;

// Test cases
public class CountSpecialTriplets {
	public static void main(String[] args) {
		Solution obj = new Solution();

		// case 1
		int[] nums1 = {6, 3, 6};
		System.out.println("Result of test case 1 : " + obj.specialTriplets(nums1)); // Expected: 1

		// case 2
		int[] nums2 = {0, 1, 0, 0};
		System.out.println("Result of test case 2 : " + obj.specialTriplets(nums2)); // Expected: 1

		// case 3
		int[] nums3 = {8, 4, 2, 8, 4};
		System.out.println("Result of test case 3 : " + obj.specialTriplets(nums3)); // Expected: 2

	}
}

class Solution {
    private static final long MOD = 1_000_000_007L;

    public int specialTriplets(int[] nums) {
        Map<Long, Long> rightCount = new HashMap<>();
        Map<Long, Long> leftCount = new HashMap<>();

        for (int x : nums) {
            rightCount.put((long)x, rightCount.getOrDefault((long)x, 0L) + 1);
        }

        long result = 0;

        for (int j = 0; j < nums.length; j++) {
            long val = nums[j];
            rightCount.put(val, rightCount.get(val) - 1);

            long target = val * 2;
            long left  = leftCount.getOrDefault(target, 0L);
            long right = rightCount.getOrDefault(target, 0L);

            result = (result + (left * right) % MOD) % MOD;

            leftCount.put(val, leftCount.getOrDefault(val, 0L) + 1);
        }

        return (int) result;
    }
}

