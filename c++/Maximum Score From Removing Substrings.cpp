#include <iostream>
#include <string>
#include <stack>
#include <cassert>
#include <stack>

class Solution {
public:
    int maximumGain(std::string s, int x, int y) {
        if (x < y) {
            std::swap(x, y);
            std::swap(removeFirst, removeSecond);
        }
        return removeAndScore(s, x, y, removeFirst, removeSecond);
    }

private:
    std::string removeFirst = "ab";
    std::string removeSecond = "ba";

    int removeAndScore(std::string &s, int x, int y, const std::string &firstPair, const std::string &secondPair) {
        std::stack<char> stack;
        int score = 0;

        for (char c : s) {
            if (!stack.empty() && stack.top() == firstPair[0] && c == firstPair[1]) {
                stack.pop();
                score += x;
            } else {
                stack.push(c);
            }
        }

        std::string remaining;
        while (!stack.empty()) {
            remaining.push_back(stack.top());
            stack.pop();
        }
        std::reverse(remaining.begin(), remaining.end());

        for (char c : remaining) {
            if (!stack.empty() && stack.top() == secondPair[0] && c == secondPair[1]) {
                stack.pop();
                score += y;
            } else {
                stack.push(c);
            }
        }

        return score;
    }
};

// Tests case
void test() {
    Solution mp;
    std::string s = "cabab";
    int x = 5;
    int y = 3;
    int expected = 8; 
    assert(mp.maximumGain(s, x, y) == expected);

    s = "aabbaaxybbaabb";
    x = 5;
    y = 4;
    expected = 32; 
    assert(mp.maximumGain(s, x, y) == expected);

    std::cout << "all test case passed!" << std::endl;
}

int main() {
    test();
    return 0;
}

