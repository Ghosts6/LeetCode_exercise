#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::string restoreString(std::string s, std::vector<int>& indices) {
        std::string result(s.size(), ' ');
        for (int i = 0; i < s.size(); ++i) {
            result[indices[i]] = s[i];
        }
        return result;
    }
};
//  test case
int main() {
    Solution solution;
    std::string s = "codeLeet"; 
    std::vector<int> indices = {4, 5, 6, 7, 0, 2, 1, 3};
    std::string shuffled = solution.restoreString(s, indices);
    std::cout << "Shuffled string: " << shuffled << std::endl;
    return 0;
}
