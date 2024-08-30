#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

class Solution {
public:
    struct Edge {
        int to, weight, index;
    };

    std::vector<std::vector<Edge>> graph;
    std::vector<long long> distance;
    std::vector<int> parent;

    std::vector<long long> dijkstra(int n, int src) {
        distance = std::vector<long long>(n, LLONG_MAX);
        parent = std::vector<int>(n, -1);
        std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> pq;
        pq.push({0, src});
        distance[src] = 0;

        while (!pq.empty()) {
            long long dist = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (dist > distance[u]) continue;

            for (Edge &edge : graph[u]) {
                int v = edge.to;
                long long w = edge.weight;
                if (distance[u] + w < distance[v]) {
                    distance[v] = distance[u] + w;
                    parent[v] = u;
                    pq.push({distance[v], v});
                }
            }
        }
        return distance;
    }

    bool possibleToMeetTarget(int n, int source, int destination, int target, std::vector<std::vector<int>>& edges) {
        graph = std::vector<std::vector<Edge>>(n);
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            graph[u].push_back({v, (w == -1 ? 1 : w), i});
            graph[v].push_back({u, (w == -1 ? 1 : w), i});
        }

        std::vector<long long> initialDistances = dijkstra(n, source);
        if (initialDistances[destination] > target) return false;

        for (int i = 0; i < edges.size(); ++i) {
            if (edges[i][2] == -1) {
                edges[i][2] = 2 * 1e9;
            }
        }

        graph.clear();
        graph.resize(n);
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            graph[u].push_back({v, w, i});
            graph[v].push_back({u, w, i});
        }

        std::vector<long long> maxDistances = dijkstra(n, source);
        if (maxDistances[destination] < target) return false;

        for (int i = 0; i < edges.size(); ++i) {
            if (edges[i][2] == 2 * 1e9) {
                edges[i][2] = maxDistances[destination] - target;
                return true;
            }
        }
        return true;
    }

    std::vector<std::vector<int>> modifiedGraphEdges(int n, std::vector<std::vector<int>>& edges, int source, int destination, int target) {
        if (possibleToMeetTarget(n, source, destination, target, edges)) {
            return edges;
        } else {
            return {};
        }
    }
};

int main() {
    Solution solution;
    int n = 5;
    std::vector<std::vector<int>> edges = {{4, 1, -1}, {2, 0, -1}, {0, 3, -1}, {4, 3, -1}};
    int source = 0;
    int destination = 1;
    int target = 5;

    std::vector<std::vector<int>> result = solution.modifiedGraphEdges(n, edges, source, destination, target);

    if (result.empty()) {
        std::cout << "Output: []" << std::endl;
    } else {
        std::cout << "Output: [";
        for (const auto& edge : result) {
            std::cout << "[" << edge[0] << "," << edge[1] << "," << edge[2] << "],";
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}
