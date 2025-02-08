#include <iostream>
#include <vector>

class Solution {
public:
    bool areAlmostEqual(std::string s1, std::string s2) {
        std::vector<std::pair<char, char>> diff;
        
        for (size_t i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                diff.emplace_back(s1[i], s2[i]);
                if (diff.size() > 2) return false;
            }
        }
        
        return diff.empty() || (diff.size() == 2 && diff[0] == std::make_pair(diff[1].second, diff[1].first));
    }
};
// Test cases
int main() {
    Solution solution;
    std::cout <<"Result of Test case 1: "<<solution.areAlmostEqual("bank", "kanb") << std::endl; // true
    std::cout <<"Result of Test case 2: "<<solution.areAlmostEqual("attack", "defend") << std::endl; // false
    std::cout <<"Result of Test case 3: "<<solution.areAlmostEqual("kelb", "kelb") << std::endl; // true
    return 0;
}