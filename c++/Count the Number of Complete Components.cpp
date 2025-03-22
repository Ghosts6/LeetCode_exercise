#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    int countCompleteComponents(int n, std::vector<std::vector<int>>& edges) {
        std::unordered_map<int, std::vector<int>> graph;
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        std::unordered_set<int> visited;
        int completeComponents = 0;

        auto dfs = [&](int node, std::unordered_set<int>& componentNodes) {
            std::vector<int> stack = {node};
            componentNodes.insert(node);
            while (!stack.empty()) {
                int current = stack.back();
                stack.pop_back();
                for (int neighbor : graph[current]) {
                    if (componentNodes.find(neighbor) == componentNodes.end()) {
                        componentNodes.insert(neighbor);
                        stack.push_back(neighbor);
                    }
                }
            }
        };

        auto isComplete = [&](const std::unordered_set<int>& componentNodes) {
            int size = componentNodes.size();
            for (int node : componentNodes) {
                if (graph[node].size() != size - 1) {
                    return false;
                }
            }
            return true;
        };

        for (int node = 0; node < n; ++node) {
            if (visited.find(node) == visited.end()) {
                std::unordered_set<int> componentNodes;
                dfs(node, componentNodes);
                visited.insert(componentNodes.begin(), componentNodes.end());
                if (isComplete(componentNodes)) {
                    completeComponents++;
                }
            }
        }

        return completeComponents;
    }
};
// Test case
int main() {
    Solution solution;
    // case 1
    std::vector<std::vector<int>> edges1 = {{0,1}, {0,2}, {1,2}, {3,4}};
    std::cout << "result of test case 1: " << solution.countCompleteComponents(6, edges1) << std::endl; // Expected out put: 3

    // case 2
    std::vector<std::vector<int>> edges2 = {{0,1}, {0,2}, {1,2}, {3,4}, {3,5}};
    std::cout << "result of test case 2: " << solution.countCompleteComponents(6, edges2) << std::endl; // Expected out put: 1

    return 0;
}
