#include <iostream>
#include <string>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int length = 0;
        int i = s.length() - 1;
        while (i >= 0 && s[i] == ' ')
            i--;

        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }
        return length;
    }
};

// test case
int main() {
    Solution sol;
    std::string str = "Hello World";
    std::cout << "Length of the last word: " << sol.lengthOfLastWord(str) << std::endl;
    return 0;
}
