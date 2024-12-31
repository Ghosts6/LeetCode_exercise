from collections import defaultdict, deque

class Solution:
    def treeDiameter(self, edges):
        def bfs(farthest_start, n):
            visited = [-1] * n
            visited[farthest_start] = 0
            q = deque([farthest_start])
            farthest_node = farthest_start
            max_distance = 0
            
            while q:
                node = q.popleft()
                for neighbor in graph[node]:
                    if visited[neighbor] == -1:
                        visited[neighbor] = visited[node] + 1
                        q.append(neighbor)
                        if visited[neighbor] > max_distance:
                            max_distance = visited[neighbor]
                            farthest_node = neighbor
            return farthest_node, max_distance

        n = len(edges) + 1
        graph = defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        start, _ = bfs(0, n)
        _, diameter = bfs(start, n)
        return diameter
    
    def minimumDiameterAfterMerge(self, edges1, edges2):
        d1 = self.treeDiameter(edges1)
        d2 = self.treeDiameter(edges2)

        return max((d1 + 1), (d2 + 1))
# Test cases
if __name__ == "__main__":
    solution = Solution()

    # case1
    edges1_1 = [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]]
    edges1_2 = [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]]
    print("Test case 1 OutPut:", solution.minimumDiameterAfterMerge(edges1_1, edges1_2)) # Expected Output: 5

    # case2
    edges2_1 = [[0,1],[0,2],[0,3]]
    edges2_2 = [[0,1]]
    print("Test case 2 OutPut:", solution.minimumDiameterAfterMerge(edges2_1, edges2_2)) # Expected Output: 3
