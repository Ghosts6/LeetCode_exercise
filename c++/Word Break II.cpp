#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

class Solution {
public:
    std::vector<std::string> wordBreak(std::string s, std::vector<std::string>& wordDict) {
        std::unordered_set<std::string> dict(wordDict.begin(), wordDict.end());
        std::unordered_map<std::string, std::vector<std::string>> memo;
        return wordBreakHelper(s, dict, memo);
    }
private:
    std::vector<std::string> wordBreakHelper(const std::string& s, std::unordered_set<std::string>& dict, std::unordered_map<std::string, std::vector<std::string>>& memo) {
        if (memo.count(s)) return memo[s];
        std::vector<std::string> result;
        if (dict.count(s)) result.push_back(s);
        for (int i = 1; i < s.size(); ++i) {
            std::string left = s.substr(0, i);
            if (dict.count(left)) {
                std::vector<std::string> subResult = wordBreakHelper(s.substr(i), dict, memo);
                for (const std::string& sub : subResult) {
                    result.push_back(left + " " + sub);
                }
            }
        }
        memo[s] = result;
        return result;
    }
};
//  test case
int main() {
    Solution solution;
    std::string s = "catsanddog";
    std::vector<std::string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    std::vector<std::string> result = solution.wordBreak(s, wordDict);
    for (const std::string& sentence : result) {
        std::cout << sentence << std::endl;
    }
    return 0;
}