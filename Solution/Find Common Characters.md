# 📜 Find Common Characters


## 💡 Intuition
1.  Problem Understanding: We need to find common characters (including duplicates) that appear in all strings within the given array words.
2.  Character Counting: We will count the occurrences of each character in every word and then find the minimum count for each character across all words.
3.  Result Construction: Based on the minimum count of each character, we construct the result.

## 🛠️ Approach
1.  Initialization:
Create a min_freq array to store the minimum frequency of each character across all words, initialized to infinity.
Count the frequency of each character in the first word and 
update the min_freq array accordingly.

2.  Frequency Update:
For each subsequent word, count the frequency of each character.
Update the min_freq array to keep track of the minimum frequency of each character across all words.
3.  Result Construction:
Iterate over the min_freq array.
For each character, if the frequency is greater than zero, append it to the result the number of times it appears.

## ⏰ Complexity
- Time complexity: Counting characters for each word takes O(n * m), where n is the number of words and m is the average length of the words.

- Space complexity: O(n * m) for the result, but O(1) for the frequency arrays.


## 💻 Code

### C++
```cpp
class Solution {
public:
    std::vector<std::string> commonChars(std::vector<std::string>& words) {
        std::vector<std::string> result;
        
        for (char c = 'a'; c <= 'z'; ++c) {
            int min_count = INT_MAX;
            
            for (const std::string& word : words) {
                int count = std::count(word.begin(), word.end(), c);
                min_count = std::min(min_count, count);
                if (min_count == 0) {
                    break;
                }
            }
            
            for (int i = 0; i < min_count; ++i) {
                result.push_back(std::string(1, c));
            }
        }
        
        return result;
    }
};
```
### C
```c
char** commonChars(char** words, int wordsSize, int* returnSize) {
    char** result = (char**)malloc(100 * sizeof(char*));
    int k = 0;

    for (char c = 'a'; c <= 'z'; ++c) {
        int min_count = INT_MAX;
        
        for (int i = 0; i < wordsSize; ++i) {
            int count = 0;
            int wordLen = strlen(words[i]);
            for (int j = 0; j < wordLen; ++j) {
                if (words[i][j] == c) {
                    count++;
                }
            }
            if (count < min_count) {
                min_count = count;
            }
            if (min_count == 0) {
                break;
            }
        }

        for (int i = 0; i < min_count; ++i) {
            result[k] = (char*)malloc(2 * sizeof(char));
            result[k][0] = c;
            result[k][1] = '\0';
            k++;
        }
    }

    *returnSize = k;
    return result;
}
```
### Python
```py
class Solution:
    def commonChars(self, words: List[str]) -> List[str]:

        min_freq = [float('inf')] * 26
        base_count = [0] * 26

        for char in words[0]:
            base_count[ord(char) - ord('a')] += 1

        for i in range(26):
            min_freq[i] = base_count[i]

        for word in words[1:]:
            char_count = [0] * 26
            for char in word:
                char_count[ord(char) - ord('a')] += 1

            for i in range(26):
                min_freq[i] = min(min_freq[i], char_count[i])


        result = []
        for i in range(26):
            result.extend([chr(i + ord('a'))] * min_freq[i])
        
        return result
```