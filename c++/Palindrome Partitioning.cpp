#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::vector<std::string>> result;
        std::vector<std::string> currentPartition;
        backtrack(s, 0, currentPartition, result);
        return result;
    }
private:
    void backtrack(const std::string &s, int start, std::vector<std::string> &currentPartition, std::vector<std::vector<std::string>> &result) {
        if (start == s.size()) {
            result.push_back(currentPartition);
            return;
        }
        for (int end = start; end < s.size(); ++end) {
            if (isPalindrome(s, start, end)) {
                currentPartition.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1, currentPartition, result);
                currentPartition.pop_back();
            }
        }
    }
    bool isPalindrome(const std::string &s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }
};
//  test case
int main() {
    Solution solution;
    std::string s = "aab";
    std::vector<std::vector<std::string>> result = solution.partition(s);
    std::cout << "possible palindrome partitioning for the string \"" << s << "\":" << std::endl;
    for (const auto &partition : result) {
        for (const auto &substring : partition) {
            std::cout << "\"" << substring << "\", ";
        }
        std::cout << std::endl;
    }
    return 0;
}
