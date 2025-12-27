<?php

class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function scoreOfString($s) {
        $score = 0;
        $length = strlen($s);

        for ($i = 0; $i < $length - 1; $i++) {
            $score += abs(ord($s[$i]) - ord($s[$i + 1]));
        }

        return $score;
    }
}

// Test cases
echo "--- Running Test Cases ---\n";

$solution = new Solution();

// Test Case 1
$s1 = "hello";
$expected1 = 13;
$result1 = $solution->scoreOfString($s1);
echo "Test Case 1 Output: " . $result1 . " (Expected: " . $expected1 . ")\n";

// Test Case 2
$s2 = "zaz";
$expected2 = 50;
$result2 = $solution->scoreOfString($s2);
echo "Test Case 2 Output: " . $result2 . " (Expected: " . $expected2 . ")\n";

?>
