# 📜 Reverse Words in a String

## 💡 Intuition
We need to reverse the order of words in a given string while preserving the order of characters within each word.

## 🛠️ Approach
1.  Split the String: First, we split the input string into an array of words. This can be achieved by using the split() function and a regular expression to split the string based on whitespace characters.
2.  Reverse the Array: Next, we reverse the array of words.
3.  Join the Words: Finally, we join the words back together into a single string, with each word separated by a single space.

## ⏰ Complexity
- Time complexity:Splitting the string into an array of words takes O(n) time, where n is the length of the input string.

- Space complexity:Splitting the string into an array of words requires additional space to store the words. The space complexity for this step is O(m), where m is the number of words.

## 💻 Code
```c++ []
class Solution {
public:
    std::string reverseWords(std::string s) {
        std::vector<std::string> words;
        std::stringstream ss(s);
        std::string word;
        while (ss >> word) {
            words.push_back(word);
        }
        std::reverse(words.begin(), words.end());
        std::stringstream result;
        for (const std::string& w : words) {
            result << w << " ";
        }
        std::string reversed = result.str();
        return reversed.substr(0, reversed.size() - 1); 
    }
};
```
```python []
class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.split()
        words.reverse()
        return ' '.join(words)
```

```javascript []
var reverseWords = function(s) {
    return s.trim().split(/\s+/).reverse().join(' ');
};
```