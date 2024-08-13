# 📜 Combination Sum III


## 💡 Intuition
This problem is a specific variant of the first one, where you are restricted to using numbers between 1 and 9, and you need to find exactly k numbers that sum to n. The constraints are tighter, but the fundamental approach remains the same: backtracking to explore possible combinations. The challenge lies in ensuring that each combination has exactly k numbers and does not exceed the sum n.

## 🛠️ Approach
Backtracking: Use a recursive function to explore all possible combinations of numbers from 1 to 9:
Start from 1 and attempt to form a combination.
Move to the next number and repeat the process until either a valid combination is found or the target sum is exceeded.
If the current number exceeds the remaining target, terminate that path early.
If a combination of exactly k numbers equals the target, store it.
Recursively explore the next number and backtrack by removing the last added number.

## ⏰ Complexity
- Time complexity:
The time complexity is O(2^9) because there are 9 possible numbers (1 to 9)

- Space complexity:
The space complexity is O(k) for the recursive stack and storing the combination.

## 💻 Code
```C++ []
class Solution {
public:
    std::vector<std::vector<int>> combinationSum3(int k, int n) {
        std::vector<std::vector<int>> result;
        std::vector<int> combination;
        backtrack(k, n, 1, combination, result);
        return result;
    }

private:
    void backtrack(int k, int target, int start, std::vector<int>& combination, std::vector<std::vector<int>>& result) {
        if (target == 0 && combination.size() == k) {
            result.push_back(combination);
            return;
        }

        for (int i = start; i <= 9; ++i) {
            if (i > target) {
                break;
            }

            combination.push_back(i);
            backtrack(k, target - i, i + 1, combination, result);
            combination.pop_back();
        }
    }
};
```