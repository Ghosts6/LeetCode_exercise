<?php
class Solution {

    /**
     * @param Integer $x
     * @return Boolean
     */
    function isPalindrome($x) {
	if ($x < 0 || ($x % 10 == 0 && $x != 0)) {
            return false;
        }

        $revertedNumber = 0;
        while ($x > $revertedNumber) {
            $revertedNumber = ($revertedNumber * 10) + ($x % 10);
            $x = (int)($x / 10);
        }

        return $x == $revertedNumber || $x == (int)($revertedNumber / 10);
    }
}

// Test cases
echo "--- Running Test Cases ---\n";

$solution = new Solution();

// Test Case 1
$x1 = 121;
$expected1 = true;
$result1 = $solution->isPalindrome($x1);
echo "Test Case 1 Output: " . $result1 . " (Expected: " . $expected1 . ")\n";

// Test Case 2
$x2 = -121;
$expected2 = false;
$result2 = $solution->isPalindrome($x2);
echo "Test Case 2 Output: " . $result2 . " (Expected: " . $expected2 . ")\n";

// Test Case 3
$x3 = 10;
$expected3 = false;
$result3 = $solution->isPalindrome($x3);
echo "Test Case 3 Output: " . $result3 . " (Expected: " . $expected3 . ")\n";

?>
