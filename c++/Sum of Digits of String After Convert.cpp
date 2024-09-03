#include <iostream>
#include <string>

class Solution {
public:
    int getLucky(std::string s, int k) {
        std::string numStr = "";
        for (char c : s) {
            int num = c - 'a' + 1;
            numStr += std::to_string(num);
        }

        int sum = 0;
        for (int i = 0; i < k; ++i) {
            sum = 0;
            for (char c : numStr) {
                sum += c - '0';
            }
            numStr = std::to_string(sum);
        }

        return sum;
    }
};
//  Test cases
int main() {
    Solution solution;

    // case 1
    std::string s1 = "iiii";
    int k1 = 1;
    std::cout << "Test case 1 - Expected: 36, Got: " << solution.getLucky(s1, k1) << std::endl;

    // case 2
    std::string s2 = "leetcode";
    int k2 = 2;
    std::cout << "Test case 2 - Expected: 6, Got: " << solution.getLucky(s2, k2) << std::endl;

    // Additional 3
    std::string s3 = "zbax";
    int k3 = 2;
    std::cout << "Test case 3 - Expected: 8, Got: " << solution.getLucky(s3, k3) << std::endl;

    return 0;
}
