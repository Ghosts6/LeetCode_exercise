#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::vector<std::string> wordSubsets(std::vector<std::string>& words1, std::vector<std::string>& words2) {
        std::vector<int> maxFreq(26, 0);
        
        for (const std::string& word : words2) {
            std::vector<int> freq(26, 0);
            for (char c : word) {
                freq[c - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                maxFreq[i] = std::max(maxFreq[i], freq[i]);
            }
        }

        std::vector<std::string> result;
        for (const std::string& word : words1) {
            std::vector<int> freq(26, 0);
            for (char c : word) {
                freq[c - 'a']++;
            }
            bool isUniversal = true;
            for (int i = 0; i < 26; ++i) {
                if (freq[i] < maxFreq[i]) {
                    isUniversal = false;
                    break;
                }
            }
            if (isUniversal) {
                result.push_back(word);
            }
        }
        
        return result;
    }
};

// Test case
int main() {
    Solution solution;

    // case 1
    std::vector<std::string> words1_1 = {"amazon", "apple", "facebook", "google", "leetcode"};
    std::vector<std::string> words2_1 = {"e", "o"};
    std::vector<std::string> result1 = solution.wordSubsets(words1_1, words2_1);
    std::cout << "Output of Test case 1: ";
    for (const std::string& word : result1) {
        std::cout << word << " "; // Expected Output: facebook, google, leetcode
    }
    std::cout << std::endl;

    // case 2
    std::vector<std::string> words1_2 = {"amazon", "apple", "facebook", "google", "leetcode"};
    std::vector<std::string> words2_2 = {"l", "e"};
    std::vector<std::string> result2 = solution.wordSubsets(words1_2, words2_2);
    std::cout << "Output of Test case 2: ";
    for (const std::string& word : result2) {
        std::cout << word << " "; // Expected Output: apple, google, leetcode
    }
    std::cout << std::endl;

    return 0;
}