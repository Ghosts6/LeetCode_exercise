<?php

class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function removeDuplicates(&$nums) {
        $count = count($nums);
        if ($count === 0) return 0;

        $k = 1;

        for ($i = 1; $i < $count; $i++) {
            if ($nums[$i] !== $nums[$i - 1]) {
                $nums[$k] = $nums[$i];
                $k++;
            }
        }

        return $k;
    }
}

// Test cases
$sol = new Solution();

// case 1
$nums1 = [1, 1, 2];
$expected1 = 2;
$result1 = $sol->removeDuplicates($nums1);
echo "Test Case 1 Output: " . $result1 . " (Expected: " . $expected1 . ")\n";

// case 2
$nums2 = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4];
$expected2 = 5;
$result2 = $sol->removeDuplicates($nums2);
echo "Test Case 2 Output: " . $result2 . " (Expected: " . $expected2 . ")\n";
