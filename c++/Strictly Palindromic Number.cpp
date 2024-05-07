#include <string>
#include <vector>
#include <cassert>

class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        if (n <= 2) return true;
        for (int base = 2; base < n - 1; ++base) {
            if (!isPalindromic(n, base)) return false;
        }
        return true;
    }
private:
    bool isPalindromic(int n, int base) {
        std::string numInBase = convertToBase(n, base);
        int left = 0, right = numInBase.size() - 1;
        while (left < right) {
            if (numInBase[left++] != numInBase[right--]) return false;
        }
        return true;
    }
    std::string convertToBase(int n, int base) {
        std::string result = "";
        while (n > 0) {
            result = std::to_string(n % base) + result;
            n /= base;
        }
        return result;
    }
};

// test case
int main() {
    Solution sol;
    
    assert(sol.isStrictlyPalindromic(6) == true);
    
    assert(sol.isStrictlyPalindromic(11) == false);
    
    return 0;
}
