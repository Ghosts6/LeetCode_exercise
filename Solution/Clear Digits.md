# 📜 Clear Digits

## 💡 Intuition  
We need to process a string and remove digits along with the character before each digit. A **stack-based approach** is ideal for this problem.

## 🛠️ Approach  
1. Use a **stack** (or a dynamic string in some languages) to store characters.
2. Iterate through the string:
   - If the character is a **digit**, remove the last element from the stack (if it exists).
   - If it is **not a digit**, add it to the stack.
3. Convert the stack back into a string and return the result.

## ⏰ Complexity  
- **Time Complexity:** $$O(n)$$, where $$n$$ is the length of the input string. We process each character once.  
- **Space Complexity:** $$O(n)$$ in the worst case (if there are no digits).  

---

## 💻 Code
```c []
char* clearDigits(const char *s) {
    int len = strlen(s), top = -1;
    char *stack = (char*)malloc(len + 1);

    for (int i = 0; i < len; i++) {
        if (isdigit(s[i])) {
            if (top >= 0) top--;
        } else {
            stack[++top] = s[i];  
        }
    }

    stack[top + 1] = '\0';
    return stack;
}

```
```cpp []
class Solution {
    public:
    std::string clearDigits(const std::string& s) {
        std::string stack;
        for (char c : s) {
            if (isdigit(c)) {
                if (!stack.empty()) stack.pop_back();
            } else {
                stack.push_back(c);
            }
        }
        return stack;
    }  
};
```
```python3 []
class Solution:
    def clearDigits(self, s: str) -> str:
        stack = []
        for c in s:
            if c.isdigit():
                if stack:
                    stack.pop()
            else:
                stack.append(c)
        return "".join(stack)
```
```javascript []
var clearDigits = function(s) {
    let stack = [];
    for (let i = 0; i < s.length; i++) {
        let c = s[i];
        if (c >= '0' && c <= '9') {
            if (stack.length) stack.pop();
        } else {
            stack.push(c);
        }
    }
    return stack.join('');
};
```