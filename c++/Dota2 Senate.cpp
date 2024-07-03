#include <iostream>
#include <queue>
#include <string>

class Solution {
public:
    std::string predictPartyVictory(std::string senate) {
        std::queue<int> radiant, dire;

        for (int i = 0; i < senate.size(); ++i) {
            if (senate[i] == 'R') {
                radiant.push(i);
            } else {
                dire.push(i);
            }
        }

        int n = senate.size();

        while (!radiant.empty() && !dire.empty()) {
            int r = radiant.front();
            int d = dire.front();
            radiant.pop();
            dire.pop();

            if (r < d) {
                radiant.push(r + n);
            } else {
                dire.push(d + n);
            }
        }

        return radiant.empty() ? "Dire" : "Radiant";
    }
};
//  test case
int main() {
    Solution solution;
    std::string senate = "RDDRR";
    std::cout << "result: " << solution.predictPartyVictory(senate) << std::endl;
    return 0;
}