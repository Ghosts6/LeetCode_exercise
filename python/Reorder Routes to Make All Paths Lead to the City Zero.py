from collections import defaultdict

class Solution:
    def minReorder(self, n: int, connections: list[list[int]]) -> int:
        graph = defaultdict(list)
        directed = set()

        for a, b in connections:
            graph[a].append(b)
            graph[b].append(a)
            directed.add((a, b))
        
        def dfs(city, parent):
            reorders = 0
            for neighbor in graph[city]:
                if neighbor == parent:
                    continue
                if (city, neighbor) in directed:
                    reorders += 1
                reorders += dfs(neighbor, city)
            return reorders

        return dfs(0, -1)

# test case
solution = Solution()
print(solution.minReorder(6, [[0,1],[1,3],[2,3],[4,0],[4,5]])) 
print(solution.minReorder(5, [[1,0],[1,2],[3,2],[3,4]]))      
print(solution.minReorder(3, [[1,0],[2,0]]))
