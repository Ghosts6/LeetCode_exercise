from collections import defaultdict

class Solution:
    def countCompleteComponents(self, n: int, edges: list[list[int]]) -> int:
        graph = defaultdict(list)
        for a, b in edges:
            graph[a].append(b)
            graph[b].append(a)

        visited = set()
        complete_components = 0

        def dfs(node, component_nodes):
            stack = [node]
            component_nodes.add(node)
            while stack:
                current = stack.pop()
                for neighbor in graph[current]:
                    if neighbor not in component_nodes:
                        component_nodes.add(neighbor)
                        stack.append(neighbor)

        def is_complete(component_nodes):
            size = len(component_nodes)

            for node in component_nodes:
                if len(graph[node]) != size - 1:
                    return False
            return True

        for node in range(n):
            if node not in visited:
                component_nodes = set()
                dfs(node, component_nodes)
                visited.update(component_nodes)
                if is_complete(component_nodes):
                    complete_components += 1

        return complete_components


# Test cases
if __name__ == "__main__":
    # case 1
    n = 6
    edges = [[0, 1], [0, 2], [1, 2], [3, 4]]
    solution = Solution()
    print("Test Case 1 Output:", solution.countCompleteComponents(n, edges))  # Expected Output: 3

    # case 2
    n = 6
    edges = [[0, 1], [0, 2], [1, 2], [3, 4], [3, 5]]
    print("Test Case 2 Output:", solution.countCompleteComponents(n, edges))  # Expected Output: 1
