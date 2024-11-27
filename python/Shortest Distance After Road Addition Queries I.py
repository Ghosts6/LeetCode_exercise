import heapq

class Solution:
    def shortestDistanceAfterQueries(self, n, queries):
        graph = {i: [i + 1] for i in range(n - 1)}
        graph[n - 1] = []

        def dijkstra():
            dist = [float('inf')] * n
            dist[0] = 0
            heap = [(0, 0)]  

            while heap:
                current_dist, node = heapq.heappop(heap)
                if current_dist > dist[node]:
                    continue
                for neighbor in graph[node]:
                    new_dist = current_dist + 1
                    if new_dist < dist[neighbor]:
                        dist[neighbor] = new_dist
                        heapq.heappush(heap, (new_dist, neighbor))

            return dist[n - 1]

        result = []
        for ui, vi in queries:
            if vi not in graph[ui]:
                graph[ui].append(vi)
            result.append(dijkstra())

        return result

# Test cases
if __name__ == "__main__":
    # case 1
    n = 5
    queries = [[2, 4], [0, 2], [0, 4]]
    print("Output for Test Case 1:", Solution().shortestDistanceAfterQueries(n, queries))  # Expected: [3, 2, 1]

    # case 2
    n = 4
    queries = [[0, 3], [0, 2]]
    print("Output for Test Case 2:", Solution().shortestDistanceAfterQueries(n, queries))  # Expected: [1, 1]
