#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    std::vector<std::vector<int>> buildMatrix(int k, std::vector<std::vector<int>>& rowConditions, std::vector<std::vector<int>>& colConditions) {
        std::vector<int> rowOrder = topologicalSort(k, rowConditions);
        std::vector<int> colOrder = topologicalSort(k, colConditions);
        
        if (rowOrder.empty() || colOrder.empty()) return {};
        
        std::vector<std::vector<int>> result(k, std::vector<int>(k, 0));
        std::unordered_map<int, int> rowIndex, colIndex;
        
        for (int i = 0; i < k; ++i) {
            rowIndex[rowOrder[i]] = i;
            colIndex[colOrder[i]] = i;
        }
        
        for (int num = 1; num <= k; ++num) {
            result[rowIndex[num]][colIndex[num]] = num;
        }
        
        return result;
    }

private:
    std::vector<int> topologicalSort(int k, const std::vector<std::vector<int>>& conditions) {
        std::unordered_map<int, std::vector<int>> graph;
        std::unordered_map<int, int> inDegree;
        
        for (int i = 1; i <= k; ++i) {
            inDegree[i] = 0;
            graph[i] = {};
        }
        
        for (const auto& cond : conditions) {
            graph[cond[0]].push_back(cond[1]);
            ++inDegree[cond[1]];
        }
        
        std::stack<int> stack;
        for (int i = 1; i <= k; ++i) {
            if (inDegree[i] == 0) stack.push(i);
        }
        
        std::vector<int> order;
        while (!stack.empty()) {
            int node = stack.top();
            stack.pop();
            order.push_back(node);
            
            for (const int& neighbor : graph[node]) {
                if (--inDegree[neighbor] == 0) stack.push(neighbor);
            }
        }
        
        if (order.size() != k) return {};
        return order;
    }
};

int main() {
    Solution sol;
    int k = 3;
    std::vector<std::vector<int>> rowConditions = {{1, 2}, {3, 2}};
    std::vector<std::vector<int>> colConditions = {{2, 1}, {3, 2}};
    std::vector<std::vector<int>> result = sol.buildMatrix(k, rowConditions, colConditions);
    
    if (result.empty()) {
        std::cout << "No valid matrix exists." << std::endl;
    } else {
        for (const auto& row : result) {
            for (const auto& num : row) {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        }
    }
    return 0;
}
