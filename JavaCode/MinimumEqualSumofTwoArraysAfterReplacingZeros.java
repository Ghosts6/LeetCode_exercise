package JavaCode;
import java.util.*;

public class MinimumEqualSumofTwoArraysAfterReplacingZeros {
    public long minSum(int[] nums1, int[] nums2) {
        long sum1 = 0, sum2 = 0;
        int zeroCount1 = 0, zeroCount2 = 0;

        for (int num : nums1) {
            if (num == 0) {
                zeroCount1++;
                sum1 += 1;
            } else {
                sum1 += num;
            }
        }

        for (int num : nums2) {
            if (num == 0) {
                zeroCount2++;
                sum2 += 1;
            } else {
                sum2 += num;
            }
        }

        if (sum1 == sum2) {
            return sum1;
        }

        if (sum1 > sum2) {
            long diff = sum1 - sum2;
            if (zeroCount2 == 0) {
                return -1;
            }
            return sum1;
        } else {
            long diff = sum2 - sum1;
            if (zeroCount1 == 0) {
                return -1; 
            }
            return sum2;
        }
    }
}


