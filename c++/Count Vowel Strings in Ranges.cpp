#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> vowelStrings(const std::vector<std::string>& words, const std::vector<std::vector<int>>& queries) {
        std::vector<int> prefixCount(words.size() + 1, 0);
        std::vector<int> result;

        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        for (size_t i = 0; i < words.size(); ++i) {
            if (isVowel(words[i].front()) && isVowel(words[i].back())) {
                prefixCount[i + 1] = prefixCount[i] + 1;
            } else {
                prefixCount[i + 1] = prefixCount[i];
            }
        }

        for (const auto& query : queries) {
            int li = query[0];
            int ri = query[1];
            result.push_back(prefixCount[ri + 1] - prefixCount[li]);
        }

        return result;
    }
};
// Test cases
int main() {
    Solution solution;
    // Case 1
    std::vector<std::string> words1 = {"aba", "bcb", "ece", "aa", "e"};
    std::vector<std::vector<int>> queries1 = {{0, 2}, {1, 4}, {1, 1}};
    std::vector<int> result1 = solution.vowelStrings(words1, queries1);
    std::cout << "Test Case 1 Output: ";
    for (int val : result1) {
        std::cout << val << " ";
    }
    std::cout << std::endl; // Expected Output: 2 3 0
    // Case 2
    std::vector<std::string> words2 = {"a", "e", "i"};
    std::vector<std::vector<int>> queries2 = {{0, 2}, {0, 1}, {2, 2}};
    std::vector<int> result2 = solution.vowelStrings(words2, queries2);
    std::cout << "Test Case 2 Output: ";
    for (int val : result2) {
        std::cout << val << " ";
    }
    std::cout << std::endl; // Expected Output: 3 2 1

    return 0;
}
