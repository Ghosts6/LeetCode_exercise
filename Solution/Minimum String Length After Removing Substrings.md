# 📏 Efficient String Reduction for Minimum Length

## 💡 Problem Overview
You are given a string `s` consisting only of uppercase English letters. The task is to repeatedly remove occurrences of the substrings `"AB"` or `"CD"` until no such substrings remain. The goal is to find the minimum possible length of the string after all operations.

### Example
- **Input**: `s = "ABFCACDB"`
  - **Output**: `2`
  - **Explanation**: 
    - Remove `"AB"`, resulting in `"FCACDB"`.
    - Remove `"CD"`, resulting in `"FCAB"`.
    - Remove `"AB"`, resulting in `"FC"`.
  - The remaining string length is `2`.

## 💡 Intuition
The problem revolves around reducing the string by removing specific pairs until no more matches are available. A stack-based approach helps us efficiently track and eliminate these pairs as they occur.

By utilizing a stack, we can keep track of character sequences, removing pairs as soon as they form. This ensures that all possible substrings `"AB"` and `"CD"` are handled in a single pass through the string.

## 🛠️ Approach
1. **Initialize a stack**: This will store characters that cannot be immediately removed.
2. **Iterate through each character** in the string:
   - If the stack's top character combined with the current character forms `"AB"` or `"CD"`, pop from the stack to simulate removal.
   - Otherwise, push the character onto the stack.
3. **Return the stack's size**: The stack will contain the irreducible characters, representing the minimum length of the string after all possible reductions.

## ⏰ Complexity Analysis
- **Time Complexity**: O(n), where `n` is the length of the string, as each character is pushed and popped from the stack at most once.
- **Space Complexity**: O(n), in the worst case where no pairs are found, and all characters are stored in the stack.

## 💻 Code Implementations
```cpp []
class Solution {
public:
    int minLength(std::string s) {
        std::stack<char> st;
        for (char c : s) {
            if (!st.empty() && ((st.top() == 'A' && c == 'B') || (st.top() == 'C' && c == 'D'))) {
                st.pop(); 
            } else {
                st.push(c);  
            }
        }
        return st.size();  
    }
};
```
```python3 []
class Solution:
    def minLength(self, s: str) -> int:
        stack = []
        for c in s:
            if stack and ((stack[-1] == 'A' and c == 'B') or (stack[-1] == 'C' and c == 'D')):
                stack.pop()  
            else:
                stack.append(c)
        return len(stack) 
```
```js []
var minLength = function (s) {
    const stack = [];
    for (let c of s) {
        if (stack.length && ((stack[stack.length - 1] === 'A' && c === 'B') || (stack[stack.length - 1] === 'C' && c === 'D'))) {
            stack.pop();  
        } else {
            stack.push(c);
        }
    }
    return stack.length;
}
```