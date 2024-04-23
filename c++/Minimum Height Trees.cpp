#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

class Solution {
public:
    std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>>& edges) {
        if (n == 1) return {0};

        std::vector<std::unordered_set<int>> graph(n);
        std::vector<int> indegree(n, 0);

        for (const auto& edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
            indegree[edge[0]]++;
            indegree[edge[1]]++;
        }

        std::queue<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 1) {
                leaves.push(i);
            }
        }

        int remainingNodes = n;
        while (remainingNodes > 2) {
            int numLeaves = leaves.size();
            remainingNodes -= numLeaves;

            for (int i = 0; i < numLeaves; ++i) {
                int leaf = leaves.front();
                leaves.pop();

                for (int neighbor : graph[leaf]) {
                    if (--indegree[neighbor] == 1) {
                        leaves.push(neighbor);
                    }
                }
            }
        }

        std::vector<int> mhtRoots;
        while (!leaves.empty()) {
            mhtRoots.push_back(leaves.front());
            leaves.pop();
        }
        return mhtRoots;
    }
};
// test case 
int main() {
    Solution sol;
    int n = 6;
    std::vector<std::vector<int>> edges = {{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}};
    std::vector<int> result = sol.findMinHeightTrees(n, edges);
    std::cout << "result:";
    for (int root : result) {
        std::cout << " " << root;
    }
    std::cout << std::endl;
    return 0;
}
