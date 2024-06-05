#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

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

//  test cases
int main() {
    Solution sol;

    std::vector<std::string> words1 = {"bella", "label", "roller"};
    std::vector<std::string> result1 = sol.commonChars(words1);
    std::cout << "Test Case 1: ";
    for (const std::string& s : result1) {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    std::vector<std::string> words2 = {"cool", "lock", "cook"};
    std::vector<std::string> result2 = sol.commonChars(words2);
    std::cout << "Test Case 2: ";
    for (const std::string& s : result2) {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    return 0;
}
