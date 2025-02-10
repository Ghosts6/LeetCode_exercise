# 📜 Check if One String Swap Can Make Strings Equal

## 💡 Intuition  
If two strings are already equal, no swap is needed. If they differ in more than two places, swapping just one pair of characters won’t make them equal.  
Thus, we need to check whether there are at most two mismatched characters and whether swapping them results in equality.  

## 🛠️ Approach  
1. **Compare characters** at the same index in both strings.  
2. **Store mismatched pairs** in a list or array.  
3. **Check conditions**:  
   - If there are more than 2 mismatches, return `false`.  
   - If there are exactly 2 mismatches, ensure they can be swapped.  
   - If there are no mismatches, return `true` (strings are already equal).  

## ⏰ Complexity  
- **Time Complexity:** \(O(n)\), where \(n\) is the length of the string (single pass).  
- **Space Complexity:** \(O(1)\) for the C++ and JavaScript solutions, and \(O(2)\) (i.e., \(O(1)\)) for Python due to the list of mismatched pairs.

## 💻 Code
```C++ []
class Solution {
public:
    bool areAlmostEqual(std::string s1, std::string s2) {
        std::vector<std::pair<char, char>> diff;
        
        for (size_t i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                diff.emplace_back(s1[i], s2[i]);
                if (diff.size() > 2) return false;
            }
        }
        
        return diff.empty() || (diff.size() == 2 && diff[0] == std::make_pair(diff[1].second, diff[1].first));
    }
};
```
```javascript []
const areAlmostEqual = function(s1, s2) {
    if (s1.length !== s2.length) return false;

    let diff = [];

    for (let i = 0; i < s1.length; ++i) {
        if (s1[i] !== s2[i]) {
            diff.push([s1[i], s2[i]]);
            if (diff.length > 2) return false;
        }
    }

    return diff.length === 0 || (diff.length === 2 && diff[0][0] === diff[1][1] && diff[0][1] === diff[1][0]);
};
```
```Python []
class Solution:
    def areAlmostEqual(self, s1:str, s2:str) -> bool:
        diff = [(a, b) for a, b in zip(s1, s2) if a != b]
        return not diff or len(diff) == 2 and diff[0] == diff[1][::-1]
```