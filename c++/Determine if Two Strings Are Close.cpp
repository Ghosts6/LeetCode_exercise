#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    bool closeStrings(std::string word1, std::string word2) {
        if (word1.size() != word2.size()) {
            return false;
        }

        std::unordered_map<char, int> count1;
        std::unordered_map<char, int> count2;

        for (char c : word1) {
            count1[c]++;
        }
        for (char c : word2) {
            count2[c]++;
        }

        if (count1.size() != count2.size()) {
            return false;
        }

        for (const auto& kv : count1) {
            if (count2.find(kv.first) == count2.end()) {
                return false;
            }
        }

        std::vector<int> freq1;
        std::vector<int> freq2;

        for (const auto& kv : count1) {
            freq1.push_back(kv.second);
        }
        for (const auto& kv : count2) {
            freq2.push_back(kv.second);
        }

        std::sort(freq1.begin(), freq1.end());
        std::sort(freq2.begin(), freq2.end());

        return freq1 == freq2;
    }
};

// test case
int main() {
    Solution sol;
    std::string word1 = "abc";
    std::string word2 = "bca";

    bool result = sol.closeStrings(word1, word2);
    std::cout << (result ? "True" : "False") << std::endl; 

    return 0;

}