#include <string>
#include <unordered_set>
#include <iostream>

class Solution {
public:
    int numJewelsInStones(std::string jewels, std::string stones) {
        std::unordered_set<char> jewelSet(jewels.begin(), jewels.end());
        int jewelCount = 0;
        for (char stone : stones) {
            if (jewelSet.count(stone) > 0) {
                jewelCount++;
            }
        }
        return jewelCount;
    }
};
//  test case
int main() {
    Solution sol;
    std::string jewels = "aA";
    std::string stones = "aAAbbbb";
    int count = sol.numJewelsInStones(jewels, stones);
    std::cout << "result of test case: " << count << std::endl;
    return 0;
}
