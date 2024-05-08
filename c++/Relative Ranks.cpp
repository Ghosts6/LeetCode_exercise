#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    std::vector<std::string> findRelativeRanks(std::vector<int>& score) {
        std::vector<std::string> result(score.size());
        std::map<int, int, std::greater<int>> sortedScores; 
        for (int i = 0; i < score.size(); ++i) {
            sortedScores[score[i]] = i;
        }
        int rank = 1;
        for (const auto& entry : sortedScores) {
            if (rank == 1) {
                result[entry.second] = "Gold Medal";
            } else if (rank == 2) {
                result[entry.second] = "Silver Medal";
            } else if (rank == 3) {
                result[entry.second] = "Bronze Medal";
            } else {
                result[entry.second] = std::to_string(rank);
            }
            ++rank;
        }
        return result;
    }
};
//  test case
int main() {
    Solution sol;
    std::vector<int> scores = {10, 3, 8, 9, 4};
    std::vector<std::string> result = sol.findRelativeRanks(scores);
    for (const auto& rank : result) {
        std::cout << rank << " ";
    }
    std::cout << std::endl;
    return 0;
}
