#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    int longestPalindrome(string s) {
        int res = 0, val = 0;
        unordered_map<char, int> mp;
        for (char ch : s) {
            mp[ch]++;
        }
        for (auto entry : mp) {
            if (entry.second % 2 != 0) {
                res += entry.second - 1;
                val = 1;
            } else {
                res += entry.second;
            }
        }
        return res + val;
    }
};

//  test
int main() {
    Solution lp;
    std::string testStr = "abccccdd";
    int longestLength = lp.longestPalindrome(testStr);
    std::cout << "Length of longest palindrome in '" << testStr << "': " << longestLength << std::endl;
    return 0;
}