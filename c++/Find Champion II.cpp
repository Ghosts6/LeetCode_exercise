#include <iostream>
#include <vector>
#include <bitset>

class Solution {
public:
    int findChampion(int n, std::vector<std::vector<int>>& edges) {
        std::bitset<100> losses;

        for (const auto& edge : edges) {
            losses.set(edge[1]);
        }

        int champion = -1;
        for (int i = 0; i < n; ++i) {
            if (!losses[i]) {
                if (champion != -1) {
                    return -1;
                }
                champion = i;
            }
        }

        return champion;
    }
};
// Test cases
int main() {
    Solution solution;

    // Case 1
    int n1 = 3;
    std::vector<std::vector<int>> edges1 = {{0, 1}, {1, 2}};
    std::cout << "Champion: " << solution.findChampion(n1, edges1) << "\n"; // Expected: 0

    // Case 2
    int n2 = 4;
    std::vector<std::vector<int>> edges2 = {{0, 2}, {1, 3}, {1, 2}};
    std::cout << "Champion: " << solution.findChampion(n2, edges2) << "\n"; // Expected: -1

    // Case 3
    int n3 = 5;
    std::vector<std::vector<int>> edges3 = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
    std::cout << "Champion: " << solution.findChampion(n3, edges3) << "\n"; // Expected: 0

    return 0;
}
