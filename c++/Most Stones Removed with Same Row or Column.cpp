#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

class UnionFind {
public:
    UnionFind(int n) : parent(n), rank(n, 0) {
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

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                ++rank[rootX];
            }
        }
    }

private:
    std::vector<int> parent;
    std::vector<int> rank;
};

class Solution {
public:
    int removeStones(const std::vector<std::vector<int>>& stones) {
        int n = stones.size();
        UnionFind uf(n);
        std::unordered_map<int, int> rowMap, colMap;

        for (int i = 0; i < n; ++i) {
            int row = stones[i][0];
            int col = stones[i][1];
            if (rowMap.count(row)) {
                uf.unionSets(i, rowMap[row]);
            }
            if (colMap.count(col)) {
                uf.unionSets(i, colMap[col]);
            }
            rowMap[row] = i;
            colMap[col] = i;
        }

        std::unordered_set<int> components;
        for (int i = 0; i < n; ++i) {
            components.insert(uf.find(i));
        }

        return n - components.size();
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> stones1 = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    std::vector<std::vector<int>> stones2 = {{0,0},{0,2},{1,1},{2,0},{2,2}};

    std::cout << "Output 1: " << sol.removeStones(stones1) << std::endl;
    std::cout << "Output 2: " << sol.removeStones(stones2) << std::endl;

    return 0;
}
