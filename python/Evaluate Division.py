from typing import List, Dict, Set

class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        graph = {}
        
        def add_edge(a: str, b: str, value: float):
            if a not in graph:
                graph[a] = {}
            if b not in graph:
                graph[b] = {}
            graph[a][b] = value
            graph[b][a] = 1 / value
        
        for (a, b), value in zip(equations, values):
            add_edge(a, b, value)
        
        def dfs(src: str, dst: str, visited: Set[str]) -> float:
            if src == dst:
                return 1.0
            visited.add(src)
            for neighbor, value in graph.get(src, {}).items():
                if neighbor not in visited:
                    result = dfs(neighbor, dst, visited)
                    if result != -1.0:
                        return result * value
            return -1.0

        results = []
        for c, d in queries:
            if c in graph and d in graph:
                results.append(dfs(c, d, set()))
            else:
                results.append(-1.0)
        
        return results

# test case
equations = [["a", "b"], ["b", "c"]]
values = [2.0, 3.0]
queries = [["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"]]

sol = Solution()
results = sol.calcEquation(equations, values, queries)
print(results)
