#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

class Solution {
public:
    int findRotateSteps(std::string ring, std::string key) {
        std::unordered_map<char, std::vector<int>> charIndices;
        for (int i = 0; i < ring.size(); ++i) {
            charIndices[ring[i]].push_back(i);
        }
        std::vector<std::vector<int>> memo(key.size(), std::vector<int>(ring.size(), -1));

        return dp(ring, key, 0, 0, charIndices, memo) + key.size();
    }

    int dp(const std::string& ring, const std::string& key, int keyIndex, int ringIndex, const std::unordered_map<char, std::vector<int>>& charIndices, std::vector<std::vector<int>>& memo) {
        if (keyIndex == key.size()) return 0;

        if (memo[keyIndex][ringIndex] != -1) return memo[keyIndex][ringIndex];

        char currentChar = key[keyIndex];
        const std::vector<int>& indices = charIndices.at(currentChar);
        int minSteps = INT_MAX;
        for (int index : indices) {
            int stepsToAlign = std::min(std::abs(index - ringIndex), (int)ring.size() - std::abs(index - ringIndex));
            int steps = stepsToAlign + dp(ring, key, keyIndex + 1, index, charIndices, memo);
            minSteps = std::min(minSteps, steps);
        }

        memo[keyIndex][ringIndex] = minSteps;
        return minSteps;
    }
};

// test case
int main() {
    Solution sol;
    std::string ring = "godding";
    std::string key = "gd";
    int result = sol.findRotateSteps(ring, key);
    std::cout << "result: " << result << std::endl;
    return 0;
}
