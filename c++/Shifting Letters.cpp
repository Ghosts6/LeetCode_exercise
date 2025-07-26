#include <string>
#include <vector>

class Solution {
public:
    std::string shiftingLetters(std::string s, std::vector<int>& shifts) {
        int n = s.size();
        long long totalShift = 0;
        
        // Traverse from end to start to accumulate shifts
        for (int i = n - 1; i >= 0; --i) {
            totalShift = (totalShift + shifts[i]) % 26;
            s[i] = (s[i] - 'a' + totalShift) % 26 + 'a';
        }
        
        return s;
    }
};

// Test cases
#include <iostream>

int main() {
    Solution solution;

    std::string s1 = "abc";
    std::vector<int> shift1 = {3, 5, 9};
    std::cout << solution.shiftingLetters(s1, shift1) << "\n";  // Output: rpl

    std::string s2 = "aaa";
    std::vector<int> shift2 = {1, 2, 3};
    std::cout << solution.shiftingLetters(s2, shift2) << "\n";  // Output: gfd

    return 0;
}

