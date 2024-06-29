#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

class Solution {
public:
    std::vector<std::vector<int>> getAncestors(int n, std::vector<std::vector<int>>& edges) {
        std::vector<std::vector<int>> graph(n);
        std::vector<int> in_degree(n, 0);
        
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            ++in_degree[edge[1]];
        }

        std::vector<std::set<int>> ancestors(n);
        std::queue<int> q;

        for (int i = 0; i < n; ++i) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : graph[node]) {
                ancestors[neighbor].insert(node);
                ancestors[neighbor].insert(ancestors[node].begin(), ancestors[node].end());
                if (--in_degree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        std::vector<std::vector<int>> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = std::vector<int>(ancestors[i].begin(), ancestors[i].end());
        }

        return result;
    }
};


// test case
int main() {
    Solution solution;
    int n = 8;
    std::vector<std::vector<int>> edges = {{0,3},{0,4},{1,3},{2,4},{2,7},{3,5},{3,6},{3,7},{4,6}};
    
    std::vector<std::vector<int>> result = solution.getAncestors(n, edges);
    
    std::cout << "list:\n";
    for (int i = 0; i < result.size(); ++i) {
        std::cout << "Node " << i << ": ";
        for (int ancestor : result[i]) {
            std::cout << ancestor << " ";
        }
        std::cout << "\n";
    }
    
    return 0;
}
