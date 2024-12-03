#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::string addSpaces(std::string s, std::vector<int>& spaces) {
        int n = s.size();
        int spaceIndex = 0;
        std::string result = "";

        for (int i = 0; i < n; ++i) {
            if (spaceIndex < spaces.size() && i == spaces[spaceIndex]) {
                result += ' ';  
                spaceIndex++;   
            }
            result += s[i];  
        }
        
        return result;
    }
};
// Test cases
int main() {
    Solution solution;

    // case 1
    std::string s1 = "LeetcodeHelpsMeLearn";
    std::vector<int> spaces1 = {8, 13, 15};
    std::cout << "Output 1: " << solution.addSpaces(s1, spaces1) << std::endl;

    // case 2
    std::string s2 = "icodeinpython";
    std::vector<int> spaces2 = {1, 5, 7, 9};
    std::cout << "Output 2: " << solution.addSpaces(s2, spaces2) << std::endl;

    // case 3
    std::string s3 = "spacing";
    std::vector<int> spaces3 = {0, 1, 2, 3, 4, 5, 6};
    std::cout << "Output 3: " << solution.addSpaces(s3, spaces3) << std::endl;

    return 0;
}
