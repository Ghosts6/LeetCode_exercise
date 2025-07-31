# 💡 Intuition
The problem requires us to shift letters in a string based on a series of cumulative shifts. For each `shifts[i]`, we need to shift the first `i + 1` letters. This means a character `s[j]` is affected by all shifts `shifts[i]` where `i >= j`.

A naive approach would be to calculate the total shift for each character by summing up the relevant `shifts` values. This would result in an O(n^2) time complexity. However, we can optimize this by noticing a pattern. The total shift for a character `s[i]` is the sum of all shifts from `shifts[i]` to `shifts[n-1]`. The total shift for `s[i-1]` is the shift for `s[i]` plus `shifts[i-1]`.

This relationship suggests that we can process the string from right to left. By iterating backwards, we can maintain a running total of the shifts that affect the current character. This allows us to calculate the final state of each character in a single pass.

# 🚶 Approach
The approach is to iterate through the string from right to left, accumulating the shifts and applying them to each character.

1.  Initialize a variable `totalShift` to 0. This will keep track of the cumulative shift from the right.
2.  Create a mutable representation of the input string `s` (e.g., a character array or a list of characters), as strings are often immutable.
3.  Loop from the last character of the string (`i = n-1`) down to the first (`i = 0`).
4.  Inside the loop, for each character `s[i]`:
    a. Add the corresponding `shifts[i]` to `totalShift`.
    b. The result of `totalShift` might be very large, so we take it modulo 26 to keep it within the alphabet range.
    c. Calculate the new character's position. This is done by converting the current character `s[i]` to its 0-indexed alphabet position (`s[i] - 'a'`), adding the `totalShift`, taking the result modulo 26, and then converting it back to a character by adding `'a'`.
    d. Update the character at index `i` in our mutable string with the new, shifted character.
5.  After the loop finishes, convert the mutable representation back into a string and return it.

This method ensures that each character `s[i]` is correctly shifted by the sum of `shifts[i], shifts[i+1], ..., shifts[n-1]` in O(n) time.

# 📊 Complexity
- Time complexity: O(n)
We iterate through the string and the `shifts` array once. All operations inside the loop are constant time. Therefore, the time complexity is linear with respect to the length of the string, `n`.

- Space complexity: O(n)
We use extra space to store the result. In C, we allocate a new character array. In C++, Java, Python, and JavaScript, we create a mutable copy of the string (like a char array or list) to perform the modifications. This requires space proportional to the length of the string, `n`.

# 💻 Code
```c []
char* shiftingLetters(char* s, int* shifts, int shiftsSize) {
    int n = shiftsSize;
    long totalShift = 0;

    char* result = malloc(n + 1);
    if (!result) return NULL;

    for (int i = n - 1; i >= 0; --i) {
        totalShift = (totalShift + shifts[i]) % 26;
        result[i] = 'a' + (s[i] - 'a' + totalShift) % 26;
    }

    result[n] = '\0';
    return result;
}
```
```C++ []
class Solution {
public:
    std::string shiftingLetters(std::string s, std::vector<int>& shifts) {
        int n = s.size();
        long long totalShift = 0;
        
        for (int i = n - 1; i >= 0; --i) {
            totalShift = (totalShift + shifts[i]) % 26;
            s[i] = (s[i] - 'a' + totalShift) % 26 + 'a';
        }
        
        return s;
    }
};
```
```Java []
public class Solution {
    public String shiftingLetters(String s, int[] shifts) {
        int n = s.length();
        long totalShift = 0;
        char[] chars = s.toCharArray();

        for (int i = n - 1; i >= 0; --i) {
            totalShift = (totalShift + shifts[i]) % 26;
            chars[i] = (char) ((chars[i] - 'a' + totalShift) % 26 + 'a');
        }

        return new String(chars);
    }
}
```
```js []
var shiftingLetters = function(s, shifts) {
    var n = s.length;
    var totalShift = 0;
    var result = s.split('');
    
    for (var i = n - 1; i >= 0; i--) {
        totalShift += shifts[i];
        totalShift %= 26; 
        result[i] = String.fromCharCode((s.charCodeAt(i) - 'a'.charCodeAt(0) + totalShift) % 26 + 'a'.charCodeAt(0));
    }
    
    return result.join('');
};
```
```python3 []
class Solution:
    def shiftingLetters(self, s: str, shifts: List[int]) -> str:
        n = len(s)
        total_shift = 0
        result = list(s)
        for i in range(n - 1, -1, -1):
            total_shift += shifts[i]
            result[i] = chr((ord(s[i]) - ord('a') + total_shift) % 26 + ord('a'))
        return ''.join(result)
```