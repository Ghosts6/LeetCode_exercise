#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int findCenter(std::vector<std::vector<int>>& edges) {
        std::unordered_map<int, int> degree;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            degree[u]++;
            degree[v]++;
        }

        int n = edges.size() + 1;
        for (auto& entry : degree) {
            if (entry.second == n - 1) {
                return entry.first;
            }
        }
     
        return -1;
    }
};
//  test case
int main() {
    Solution solution;
    
    std::vector<std::vector<int>> edges1 = {{1, 2}, {2, 3}, {4, 2}};
    std::cout << "test case (excepted result 2) : " << solution.findCenter(edges1) << std::endl;
    
    return 0;
}