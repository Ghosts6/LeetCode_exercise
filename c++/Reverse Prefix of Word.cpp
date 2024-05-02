#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string reversePrefix(std::string word, char ch) {
        auto pos = word.find(ch);
        if (pos != std::string::npos) {
            std::reverse(word.begin(), word.begin() + pos + 1);
        }
        return word;
    }
};

// test case
int main() {
    Solution sol;
    std::string word = "abcdefd";
    char ch = 'd';
    std::string result = sol.reversePrefix(word, ch);
    std::cout<<"result :"<<result<<std::endl;
    return 0;
}