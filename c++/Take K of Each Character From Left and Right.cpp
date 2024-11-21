#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

class Solution {
public:
    int takeCharacters(std::string s, int k) {
        std::vector<int> count(3, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        if (*std::min_element(count.begin(), count.end()) < k) {
            return -1;
        }

        int res = INT_MAX;
        int l = 0;

        for (int r = 0; r < s.length(); r++) {
            count[s[r] - 'a']--;
            
            while (*std::min_element(count.begin(), count.end()) < k) {
                count[s[l] - 'a']++;
                l++;
            }

            res = std::min(res, static_cast<int>(s.length()) - (r - l + 1));
        }

        return res;
    }
};
// Test cases
int main() {
    Solution solution;
    // case 1
    std::string s1 = "aabaaaacaabc";
    int k1 = 2;
    std::cout << "Test case 1: " << solution.takeCharacters(s1, k1) << std::endl;

    // case 2
    std::string s2 = "a";
    int k2 = 1;
    std::cout << "Test case 2: " << solution.takeCharacters(s2, k2) << std::endl;

    // case 3 Edge case 
    std::string s3 = "aaaaaaa";
    int k3 = 3;
    std::cout << "Test case 3: " << solution.takeCharacters(s3, k3) << std::endl;

    return 0;
}
