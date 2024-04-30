#include <iostream>
#include <string>
#include <unordered_map>


class Solution {
public:
    long long wonderfulSubstrings(std::string word) {
        std::unordered_map<int, long long> count; 
        count[0] = 1;
        long long result = 0, prefix = 0; 
        int n = word.size();
        for (int i = 0; i < n; ++i) {
            prefix ^= 1 << (word[i] - 'a');
            result += count[prefix];
            for (int j = 0; j < 10; ++j) {
                result += count[prefix ^ (1 << j)];
            }
            count[prefix]++;
        }
        return result;
    }
};

// test case
int main() {
    Solution sol;
    std::string word = "ababa";
    int result = sol.wonderfulSubstrings(word);
    std::cout << "result: " << result << std::endl; 
    return 0;
}