#include <vector>
#include <queue>
#include <iostream>
#include <iomanip>

class Solution {
public:
    double maxProbability(int n, std::vector<std::vector<int>>& edges, std::vector<double>& succProb, int start, int end) {
        std::vector<std::vector<std::pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); ++i) {
            int a = edges[i][0];
            int b = edges[i][1];
            double prob = succProb[i];
            graph[a].emplace_back(b, prob);
            graph[b].emplace_back(a, prob);
        }
        
        std::priority_queue<std::pair<double, int>> pq;
        pq.push({1.0, start});
        
        std::vector<double> maxProb(n, 0.0);
        maxProb[start] = 1.0;
        
        while (!pq.empty()) {
            double currentProb = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if (node == end) {
                return currentProb;
            }
            
            for (const auto& neighbor : graph[node]) {
                int nextNode = neighbor.first;
                double edgeProb = neighbor.second;
                double newProb = currentProb * edgeProb;
                
                if (newProb > maxProb[nextNode]) {
                    maxProb[nextNode] = newProb;
                    pq.push({newProb, nextNode});
                }
            }
        }
        
        return 0.0;
    }
};
//  Test cases
int main() {
    Solution sol;
    std::vector<std::vector<int>> edges1 = {{0,1},{1,2},{0,2}};
    std::vector<double> succProb1 = {0.5, 0.5, 0.2};
    int start1 = 0, end1 = 2;
    double result1 = sol.maxProbability(3, edges1, succProb1, start1, end1);
    std::cout << std::fixed << std::setprecision(5) << result1 << std::endl;

    std::vector<std::vector<int>> edges2 = {{0,1},{1,2},{2,3},{3,4}};
    std::vector<double> succProb2 = {0.7, 0.8, 0.9, 0.6};
    int start2 = 0, end2 = 4;
    double result2 = sol.maxProbability(5, edges2, succProb2, start2, end2);
    std::cout << std::fixed << std::setprecision(5) << result2 << std::endl;

    std::vector<std::vector<int>> edges3 = {{0,1},{1,2},{2,3},{3,4}};
    std::vector<double> succProb3 = {0.5, 0.4, 0.3, 0.2};
    int start3 = 0, end3 = 3;
    double result3 = sol.maxProbability(5, edges3, succProb3, start3, end3);
    std::cout << std::fixed << std::setprecision(5) << result3 << std::endl;

    return 0;
}