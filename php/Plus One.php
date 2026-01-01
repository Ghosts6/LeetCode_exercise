<?php

class Solution {
    /**
     * @param Integer[] $digits
     * @return Integer[]
     */
    public function plusOne(array $digits): array {
        $n = count($digits);
        $digits[$n - 1]++;

        for ($i = $n - 1; $i > 0; $i--) {
            if ($digits[$i] === 10) {
                $digits[$i] = 0;
                $digits[$i - 1]++;
            } else {
                break;
            }
        }

        if ($digits[0] === 10) {
            $digits[0] = 0;
            array_unshift($digits, 1);
        }

        return $digits;
    }
}

// Test cases
echo "--- Running Test Cases ---\n";

$solution = new Solution();

// Test Case 1
$digits1 = [1, 2, 3];
$expected1 = [1, 2, 4];
$result1 = $solution->plusOne($digits1);
echo "Test Case 1 Output: " . json_encode($result1) .
     " (Expected: " . json_encode($expected1) . ")\n";

// Test Case 2
$digits2 = [4, 3, 2, 1];
$expected2 = [4, 3, 2, 2];
$result2 = $solution->plusOne($digits2);
echo "Test Case 2 Output: " . json_encode($result2) .
     " (Expected: " . json_encode($expected2) . ")\n";

// Test Case 3
$digits3 = [9];
$expected3 = [1, 0];
$result3 = $solution->plusOne($digits3);
echo "Test Case 3 Output: " . json_encode($result3) .
     " (Expected: " . json_encode($expected3) . ")\n";

?>
