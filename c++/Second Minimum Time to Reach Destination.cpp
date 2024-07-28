#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

class Solution {
public:
    struct State {
        int node;
        int time;
        bool operator>(const State& other) const {
            return time > other.time;
        }
    };
    
    int secondMinimum(int n, std::vector<std::vector<int>>& edges, int time, int change) {
        std::vector<std::vector<int>> graph(n + 1);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        std::vector<int> minTime(n + 1, INT_MAX);
        std::vector<int> secondMinTime(n + 1, INT_MAX);
        std::priority_queue<State, std::vector<State>, std::greater<State>> pq;
        
        pq.push({1, 0});
        minTime[1] = 0;
        
        while (!pq.empty()) {
            State curr = pq.top();
            pq.pop();
            int currNode = curr.node;
            int currTime = curr.time;
            
            for (int neighbor : graph[currNode]) {
                int waitTime = 0;
                if ((currTime / change) % 2 == 1) {
                    waitTime = change - (currTime % change);
                }
                int nextTime = currTime + time + waitTime;
                
                if (nextTime < minTime[neighbor]) {
                    secondMinTime[neighbor] = minTime[neighbor];
                    minTime[neighbor] = nextTime;
                    pq.push({neighbor, nextTime});
                } else if (nextTime > minTime[neighbor] && nextTime < secondMinTime[neighbor]) {
                    secondMinTime[neighbor] = nextTime;
                    pq.push({neighbor, nextTime});
                }
            }
        }
        
        return secondMinTime[n];
    }
};

//  test case
int main() {
    Solution cityTraversal;
    
    int n = 5;
    std::vector<std::vector<int>> edges = {{1, 2}, {1, 3}, {2, 4}, {3, 4}, {4, 5}};
    int time = 3;
    int change = 5;
    
    int result = cityTraversal.secondMinimum(n, edges, time, change);
    std::cout << "The second minimum time to travel from vertex 1 to vertex " << n << " is: " << result << std::endl;

    return 0;
}
