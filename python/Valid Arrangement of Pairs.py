from collections import defaultdict, deque
from typing import List

class Solution:
    def validArrangement(self, pairs: List[List[int]]) -> List[List[int]]:
        graph = defaultdict(list)
        in_degree = defaultdict(int)
        out_degree = defaultdict(int)

        for start, end in pairs:
            graph[start].append(end)
            out_degree[start] += 1
            in_degree[end] += 1

        start_node = None
        for node in out_degree:
            if out_degree[node] - in_degree[node] == 1:
                start_node = node
                break
        if not start_node:
            start_node = pairs[0][0]

        def euler_path(node: int) -> deque:
            stack = [node]
            result = deque()
            while stack:
                while graph[stack[-1]]:
                    next_node = graph[stack[-1]].pop()
                    stack.append(next_node)
                result.appendleft(stack.pop())
            return result
        
        path = euler_path(start_node)

        result = []
        for i in range(1, len(path)):
            result.append([path[i - 1], path[i]])
        
        return result

# Test cases
if __name__ == "__main__":
    solution = Solution()
    test_cases = [
        ([[5, 1], [4, 5], [11, 9], [9, 4]], [[11, 9], [9, 4], [4, 5], [5, 1]]),
        ([[1, 3], [3, 2], [2, 1]], [[1, 3], [3, 2], [2, 1]]),
        ([[1, 2], [1, 3], [2, 1]], [[1, 2], [2, 1], [1, 3]])
    ]
    
    for pairs, expected in test_cases:
        output = solution.validArrangement(pairs)
        print(f"Input: {pairs}\nOutput: {output}\n")
