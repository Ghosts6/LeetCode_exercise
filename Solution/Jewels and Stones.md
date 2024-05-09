# Jewels and Stones Solution

## 📜 Problem Description
You're given strings `jewels` representing the types of stones that are jewels, and `stones` representing the stones you have. Each character in `stones` is a type of stone you have. You want to know how many of the stones you have are also jewels.

Letters are case sensitive, so "a" is considered a different type of stone from "A".

## 💡 Intuition
The problem requires counting the number of stones that are also jewels. One way to solve it is by iterating through each stone and checking if it is present in the set of jewels.

## 🛠️ Approach
1. Convert the string `jewels` into a set to represent the types of jewels.
2. Iterate through each stone in the string `stones`.
3. For each stone, check if it is present in the set of jewels.
4. If a stone is found in the set of jewels, increment the jewel count.
5. Finally, return the total jewel count.

## ⏰ Complexity
- Time complexity:
  - C++: O(n + m), where n is the length of `jewels` and m is the length of `stones`.
  - Python: O(n + m), where n is the length of `jewels` and m is the length of `stones`.

- Space complexity:
  - C++: O(n), where n is the number of unique characters in `jewels`.
  - Python: O(n), where n is the number of unique characters in `jewels`.

## 💻 Code
### C++
```cpp
class Solution {
public:
    int numJewelsInStones(std::string jewels, std::string stones) {
        std::unordered_set<char> jewelSet(jewels.begin(), jewels.end());
        int jewelCount = 0;
        for (char stone : stones) {
            if (jewelSet.count(stone) > 0) {
                jewelCount++;
            }
        }
        return jewelCount;
    }
};
```
### python
```python
class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        jewel_set = set(jewels)
        jewel_count = 0
        for stone in stones:
            if stone in jewel_set:
                jewel_count += 1
        return jewel_count
```
### java script
```javascript
var numJewelsInStones = function(jewels, stones) {
    const jewelSet = new Set(jewels);
    let jewelCount = 0;
    for (let i = 0; i < stones.length; i++) {
        if (jewelSet.has(stones[i])) {
            jewelCount++;
        }
    }
    return jewelCount;
};
```