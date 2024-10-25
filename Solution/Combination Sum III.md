# 📜 Combination Sum III

## 🔍 Problem Overview
Given two integers `k` and `n`, the goal is to find all possible combinations of `k` distinct numbers that add up to `n`. Each number can only be chosen once and must be between 1 and 9.

**Example:**
- `k = 3`, `n = 7` should return `[[1, 2, 4]]`
- `k = 3`, `n = 9` should return `[[1, 2, 6], [1, 3, 5], [2, 3, 4]]`

## 💡 Intuition
This problem is a constrained variant of the classic combination sum problem, focusing on a fixed range of numbers (1 to 9) and an exact number of elements in each combination (`k`). The main challenge is to ensure that:
- Each combination has exactly `k` numbers.
- The numbers in each combination add up to `n`.

## 🛠️ Approach
We use **Backtracking** to explore possible combinations:
1. **Recursive Exploration**: Starting from the number `1`, attempt to form a combination by adding numbers from `1` to `9`.
2. **Termination Conditions**:
   - If the sum of a combination reaches the target `n` and contains exactly `k` elements, it’s valid and added to the results.
   - If the sum exceeds `n` or the combination exceeds `k` elements, the current path is abandoned (backtracking).
3. **Optimization**: Stop exploring further if a current number exceeds the remaining target, as subsequent numbers will only increase the sum further.

## ⏰ Complexity Analysis
- **Time Complexity**: \(O(2^9)\) due to recursive branching on numbers 1 through 9.
- **Space Complexity**: \(O(k)\), mainly for the recursive call stack and storing combinations.


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
```python3 []
class Solution:
    def combinationSum2(self, candidates, target):
        result = []  
        candidates.sort()  
        self.backtrack(candidates, target, 0, [], result)
        return result

    def backtrack(self, candidates, target, start, combination, result):
        if target == 0:  
            result.append(list(combination))
            return
        
        for i in range(start, len(candidates)):
            if i > start and candidates[i] == candidates[i - 1]: 
                continue
            
            if candidates[i] > target:  
                break
            
            combination.append(candidates[i])  
            self.backtrack(candidates, target - candidates[i], i + 1, combination, result) 
            combination.pop()  
```
```js []
var combinationSum3 = function(k, n) {
    let result = [];
    
    function backtrack(target, start, combination) {
        if (target === 0 && combination.length === k) {
            result.push([...combination]);  
            return;
        }

        for (let i = start; i <= 9; i++) {
            if (i > target) {
                break; 
            }

            combination.push(i);
            backtrack(target - i, i + 1, combination);
            combination.pop(); 
        }
    }
    
    backtrack(n, 1, []);
    return result;
};
```