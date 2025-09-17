#include <iostream>
#include <string>

class Solution {
public:
    int canBeTypedWords(const std::string& text, const std::string& brokenLetters) {
        bool broken[26] = {false};

        for (size_t i = 0; i < brokenLetters.size(); i++) {
            broken[brokenLetters[i] - 'a'] = true;
        }

        int count = 0;
        bool valid = true;

        for (size_t i = 0; i <= text.size(); i++) { // <= to process last word
            char c = (i < text.size() ? text[i] : ' '); // sentinel space at the end

            if (c == ' ') {
                if (valid) count++;
                valid = true;
            } else {
                if (broken[c - 'a']) valid = false;
            }
        }

        return count;
    }
};

// Test cases
int main() {
    Solution sol;

    // case 1
    std::string text = "hello world"; 
    std::string brokenLetters = "ad";
    std::cout << "Result of test case 1 : " 
              << sol.canBeTypedWords(text, brokenLetters) << std::endl; // Expected 1

    // case 2
    std::string text2 = "leet code";
    std::string brokenLetters2 = "lt";
    std::cout << "Result of test case 2 : " 
              << sol.canBeTypedWords(text2, brokenLetters2) << std::endl; // Expected 1

    // case 3
    std::string text3 = "leet code";
    std::string brokenLetters3 = "e";
    std::cout << "Result of test case 3 : " 
              << sol.canBeTypedWords(text3, brokenLetters3) << std::endl; // Expected 0

    return 0;
}

