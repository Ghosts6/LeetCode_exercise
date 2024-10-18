# 📜 Combination Sum II

## 💡 Intuition
The problem asks for all **unique combinations** of numbers from a given list (`candidates`) that sum up to a specified `target`. Each number in the list can be used **only once** in each combination, and the result should not contain duplicate combinations. The best way to approach this is through **backtracking** 🌀, where we explore all possible combinations of numbers while pruning paths that exceed the target or lead to duplicates.

## 🛠️ Approach
1. **Sorting** 📊: We sort the input list to handle duplicates easily and to allow early stopping when a number exceeds the target.
 
2. **Backtracking** 🔄:
   - Begin with the first candidate and try to form a combination by including it.
   - Move to the next candidate and repeat until the sum equals the target or exceeds it.
   - If the current candidate equals the previous candidate (at the same recursive depth), skip it to avoid duplicates.
   - If the sum equals the target, store the current combination.
   - Use recursion to explore further and backtrack by removing the last added number.

## ⏰ Complexity
- **Time complexity** 🕒: 
  - In the worst case, all combinations are explored, leading to a time complexity of \(O(2^n)\), where \(n\) is the number of candidates.
  
- **Space complexity** 🧠: 
  - \(O(n)\) for the recursive call stack and storing the combinations.

## 💻 Code
```C++ []
class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> combination;
        std::sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, combination, result);
        return result;
    }

private:
    void backtrack(const std::vector<int>& candidates, int target, int start, std::vector<int>& combination, std::vector<std::vector<int>>& result) {
        if (target == 0) {
            result.push_back(combination);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            if (candidates[i] > target) {
                break; 
            }

            combination.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, combination, result);
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
var combinationSum2 = function(candidates, target) {
    let result = [];  
    candidates.sort((a, b) => a - b); 
    backtrack(candidates, target, 0, [], result);
    return result;
};

function backtrack(candidates, target, start, combination, result) {
    if (target === 0) { 
        result.push([...combination]);
        return;
    }

    for (let i = start; i < candidates.length; i++) {
        if (i > start && candidates[i] === candidates[i - 1]) {
            continue;
        }

        if (candidates[i] > target) {  
            break;
        }

        combination.push(candidates[i]);  
        backtrack(candidates, target - candidates[i], i + 1, combination, result); 
        combination.pop(); 
    }
}
```