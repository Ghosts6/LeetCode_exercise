import heapq
from typing import List, Tuple

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
    
def test_solution():
    sol = Solution()
    
    # Test case 1
    n = 3
    edges = [[0, 1], [1, 2], [0, 2]]
    succProb = [0.5, 0.5, 0.2]
    start = 0
    end = 2
    assert abs(sol.maxProbability(n, edges, succProb, start, end) - 0.25) < 1e-6
    
    # Test case 2
    n = 5
    edges = [[0, 1], [1, 2], [2, 3], [3, 4], [0, 4]]
    succProb = [0.1, 0.2, 0.3, 0.4, 0.5]
    start = 0
    end = 4
    assert abs(sol.maxProbability(n, edges, succProb, start, end) - 0.1*0.5) < 1e-6
    