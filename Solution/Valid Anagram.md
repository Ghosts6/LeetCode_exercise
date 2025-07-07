# Valid Anagram 📝

## 🤔 Intuition
The core idea behind solving the anagram problem is to verify if two strings have the same characters with the same frequencies. If we can count the occurrences of each character in both strings, we can compare the counts. If the counts for every character match, the strings are anagrams. A simple and efficient way to store these counts is by using a frequency map, which can be an array or a hash map. Since the problem statement often specifies lowercase English letters, a fixed-size array of 26 is a perfect tool for this.

## ⚙️ Approach
1.  **Initial Check:** The first and most basic check is the length of the strings. If they have different lengths, they cannot be anagrams. We return `false` immediately.
2.  **Frequency Map:** We create an integer array `count` of size 26, which will serve as our frequency map for the lowercase English alphabet ('a' through 'z').
3.  **Character Counting:** We iterate through both strings `s` and `t` simultaneously.
    *   For each character from string `s`, we increment the corresponding index in our `count` array (e.g., `count[s[i] - 'a']++`).
    *   For each character from string `t`, we decrement the corresponding index (`count[t[i] - 'a']--`).
4.  **Verification:** After iterating through the strings, if they are anagrams, every character's count should have cancelled out, leaving all entries in the `count` array as zero.
5.  **Final Check:** We loop through the `count` array. If we find any non-zero value, it means the character frequencies don't match, so we return `false`.
6.  **Result:** If the entire `count` array contains only zeros, it confirms that the strings are anagrams, and we return `true`.

---

## 📊 Complexity Analysis
-   **Time Complexity:** $$O(n)$$
    *   We iterate through the strings once, where `n` is the length of the string `s` (or `t`). This takes O(n) time. The final loop to check the `count` array is constant time, O(26), which simplifies to O(1). Therefore, the dominant factor is the initial loop.

-   **Space Complexity:** $$O(1)$$
    *   We use a `count` array of a fixed size (26) to store character frequencies. This space does not grow with the input string length, so it is considered constant space.

---

## 💻 Code Implementations

### C
```c
#include <string.h>
#include <stdbool.h>

bool isAnagram(const char *s, const char *t) {
    if (strlen(s) != strlen(t)) return false;

    int count[26] = {0};

    for (int i = 0; s[i]; i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) return false;
    }

    return true;
}
```

### C++
```cpp
#include <string>
#include <vector>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size()) return false;

        int count[26] = {0};

        for (size_t i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return false;
        }

        return true;
    }
};
```

### Java
```java
class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;

        int[] count = new int[26];

        for (int i = 0; i < s.length(); i++) {
            count[s.charAt(i) - 'a']++;
            count[t.charAt(i) - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return false;
        }

        return true;
    }
}
```

### Python
```python
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        count = [0] * 26

        for ch1, ch2 in zip(s, t):
            count[ord(ch1) - ord('a')] += 1
            count[ord(ch2) - ord('a')] -= 1

        return all(c == 0 for c in count)
```