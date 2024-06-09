#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

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

//test case
int main() {
    Solution sol;
    std::string s = "hello world";
    std::cout << sol.reverseWords(s) << std::endl;
    return 0;
}
