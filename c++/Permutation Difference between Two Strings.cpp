#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    int findPermutationDifference(std::string s, std::string t) {
        std::unordered_map<char, int> indexMapS, indexMapT;
        int difference = 0;
        for (int i = 0; i < s.size(); ++i) {
            indexMapS[s[i]] = i;
        }
        for (int i = 0; i < t.size(); ++i) {
            difference += std::abs(indexMapS[t[i]] - i);
        }
        return difference;
    }
};
// test case
int main() {
    Solution solution;
    std::string s = "abc";
    std::string t = "bca";
    int result = solution.findPermutationDifference(s, t);
    std::cout << "permutation difference between s and t: " << result << std::endl;
    return 0;
}
