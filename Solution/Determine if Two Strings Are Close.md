# 📜 Determine if Two Strings Are Close

## 💡 Intuition
The goal is to determine if two strings can be transformed into each other by swapping characters within the strings. Two strings can be considered close if they contain the same set of characters and if the frequencies of these characters can be permuted to match each other.

## 🛠️ Approach
1.  Check Lengths:
If the lengths of the two strings are different, they cannot be transformed into each other, so return False.

2.  Count Character Frequencies:
Use hash maps (dictionaries) to count the frequency of each character in both strings.

3.  Check Character Sets:
Ensure both strings have the same set of unique characters.

4.  Compare Frequencies:
Sort the frequency counts and compare them. If the sorted frequency counts are the same, then the two strings can be transformed into each other.

## ⏰ Complexity
- Time complexity:

    Counting characters and checking sets both take O(n), where 
n is the length of the strings.

    Sorting the frequency counts takes O(nlogn).

- Space complexity:

    The space complexity is O(n) for storing character frequencies and the frequency arrays.

## 💻 Code

```python []
class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        if len(word1) != len(word2):
            return False

        count1 = Counter(word1)
        count2 = Counter(word2)
        

        if set(count1.keys()) != set(count2.keys()):
            return False

        return sorted(count1.values()) == sorted(count2.values())
```
```javascript []
function closeStrings(word1, word2) {
    if (word1.length !== word2.length) {
        return false;
    }

    const count1 = {};
    const count2 = {};

    for (let c of word1) {
        count1[c] = (count1[c] || 0) + 1;
    }
    for (let c of word2) {
        count2[c] = (count2[c] || 0) + 1;
    }

    if (Object.keys(count1).length !== Object.keys(count2).length) {
        return false;
    }

    for (let key in count1) {
        if (!(key in count2)) {
            return false;
        }
    }

    const freq1 = Object.values(count1).sort((a, b) => a - b);
    const freq2 = Object.values(count2).sort((a, b) => a - b);

    return JSON.stringify(freq1) === JSON.stringify(freq2);
}
```
```C++ []
class Solution {
public:
    bool closeStrings(std::string word1, std::string word2) {
        if (word1.size() != word2.size()) {
            return false;
        }

        std::unordered_map<char, int> count1;
        std::unordered_map<char, int> count2;

        for (char c : word1) {
            count1[c]++;
        }
        for (char c : word2) {
            count2[c]++;
        }

        if (count1.size() != count2.size()) {
            return false;
        }

        for (const auto& kv : count1) {
            if (count2.find(kv.first) == count2.end()) {
                return false;
            }
        }

        std::vector<int> freq1;
        std::vector<int> freq2;

        for (const auto& kv : count1) {
            freq1.push_back(kv.second);
        }
        for (const auto& kv : count2) {
            freq2.push_back(kv.second);
        }

        std::sort(freq1.begin(), freq1.end());
        std::sort(freq2.begin(), freq2.end());

        return freq1 == freq2;
    }
};
```