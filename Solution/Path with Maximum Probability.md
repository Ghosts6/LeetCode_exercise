# 📜 Path with Maximum Probability

## 💡 Intuition
The problem requires finding the path between two nodes in a weighted graph that maximizes the probability of successfully traveling from the start node to the end node. The weights in this context are probabilities of edge traversal rather than distances.

## 🛠️ Approach
1.  Graph Representation:
Use an adjacency list to represent the graph. Each node will have a list of tuples where each tuple contains a neighboring node and the probability of reaching that neighbor.

2.  Priority Queue for Maximum Probability:
Use a max-priority queue (max-heap) to always expand the path with the highest probability first. Since Python's heapq implements a min-heap, we simulate a max-heap by inserting negative probabilities.
Initialize the max-heap with the starting node and a probability of 1.0 (i.e., (-1.0, start)).

3.  Processing Nodes:
Extract nodes from the heap one by one. For each node, update the probabilities of its neighbors based on the current probability of reaching that node multiplied by the edge probability.
If a newly calculated probability for a neighbor is higher than the previously recorded probability, update it and push the neighbor into the heap.

4.  Termination:
The process continues until either the end node is extracted from the heap (in which case the corresponding probability is the maximum probability from start to end) or the heap is empty (if there’s no path to the end node).

## ⏰ Complexity
- Time complexity: O((n+E)logn)

- Space complexity: O(n+E)

## 💻 Code
```python []
class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
        graph = [[] for _ in range(n)]
        for i in range(len(edges)):
            a, b = edges[i]
            prob = succProb[i]
            graph[a].append((b, prob))
            graph[b].append((a, prob))

        max_heap = [(-1.0, start)]
        max_prob = [0.0] * n
        max_prob[start] = 1.0
        
        while max_heap:
            current_prob, node = heapq.heappop(max_heap)
            current_prob = -current_prob
            
            if node == end:
                return current_prob
            
            for neighbor, edge_prob in graph[node]:
                new_prob = current_prob * edge_prob
                if new_prob > max_prob[neighbor]:
                    max_prob[neighbor] = new_prob
                    heapq.heappush(max_heap, (-new_prob, neighbor))
        return 0.0
```
```C++ []
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
```