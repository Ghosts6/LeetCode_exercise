#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int maxLength = 0;
        int currentCost = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            currentCost += abs(s[right] - t[right]);
            while (currentCost > maxCost) {
                currentCost -= abs(s[left] - t[left]);
                ++left;
            }
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
// test case
int main() {
    Solution solution;
    string s = "abcd";
    string t = "bcdf";
    int maxCost = 3;
    
    int result = solution.equalSubstring(s, t, maxCost);
    cout << "Test case 1 result: " << result << " (Expected: 3)" << endl;
    return 0;
}
