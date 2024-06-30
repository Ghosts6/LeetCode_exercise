#include <iostream>
#include <vector>
#include <algorithm>

class DSU {
public:
    DSU(int n) : parent(n), rank(n, 1) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    bool unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            return true;
        }
        return false;
    }

private:
    std::vector<int> parent;
    std::vector<int> rank;
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, std::vector<std::vector<int>>& edges) {
        DSU dsuAlice(n + 1), dsuBob(n + 1);
        int edgesUsed = 0;

        std::sort(edges.begin(), edges.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return b[0] < a[0];
        });

        for (const auto& edge : edges) {
            int type = edge[0], u = edge[1], v = edge[2];
            if (type == 3) {
                if (dsuAlice.unionSets(u, v) | dsuBob.unionSets(u, v)) {
                    edgesUsed++;
                }
            } else if (type == 1) {
                if (dsuAlice.unionSets(u, v)) {
                    edgesUsed++;
                }
            } else if (type == 2) {
                if (dsuBob.unionSets(u, v)) {
                    edgesUsed++;
                }
            }
        }
        if (isConnected(dsuAlice, n) && isConnected(dsuBob, n)) {
            return edges.size() - edgesUsed;
        } else {
            return -1;
        }
    }

private:
    bool isConnected(DSU& dsu, int n) {
        int root = dsu.find(1);
        for (int i = 2; i <= n; ++i) {
            if (dsu.find(i) != root) {
                return false;
            }
        }
        return true;
    }
};
//  test case
int main() {
    Solution solution;
    std::vector<std::vector<int>> edges = {{3,1,2}, {3,2,3}, {1,1,3}, {1,2,4}, {1,1,2}, {2,3,4}};
    int n = 4;
    int result = solution.maxNumEdgesToRemove(n, edges);
    std::cout << "maximum number of edges that can be removed: " << result << std::endl;
    return 0;
}
