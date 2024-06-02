#include <iostream>
#include <vector>

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            std::swap(s[left], s[right]);
            ++left;
            --right;
        }
    }
};

int main() {
    Solution solution;

    std::vector<char> test = {'h', 'e', 'l', 'l', 'o'};
    solution.reverseString(test);
    for (char c : test) {
        std::cout << c;
    }
    std::cout << std::endl;

    return 0;
}
