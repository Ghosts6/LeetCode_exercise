from typing import List

class Solution:
    def findSubtreeSizes(self, parent: List[int], s: str) -> List[int]:
        """Return subtree sizes after updating each node's parent."""
        n = len(parent)
        children = [[] for _ in range(n)]

        for node in range(1, n):
            children[parent[node]].append(node)

        new_parent = parent[:]
        last_seen = {}

        def dfs(node):
            char = s[node]
            previous = last_seen.get(char)

            if node != 0 and previous is not None:
                new_parent[node] = previous

            last_seen[char] = node

            for child in children[node]:
                dfs(child)

            if previous is None:
                last_seen.pop(char, None)
            else:
                last_seen[char] = previous

        dfs(0)

        # Build the final tree.
        children = [[] for _ in range(n)]

        for node in range(1, n):
            children[new_parent[node]].append(node)

        # Calculate subtree sizes.
        answer = [1] * n

        def calculate(node):
            for child in children[node]:
                calculate(child)
                answer[node] += answer[child]

        calculate(0)

        return answer

# Test cases
if __name__ == "__main__":
    sol = Solution()

    # case 1
    parent1 = [-1, 0, 0, 1, 1, 1]
    s1 = "abaabc"
    print(f"Result of test case 1 : {sol.findSubtreeSizes(parent1, s1)}") # Expected: {6, 3, 1, 1, 1, 1}
    
    # case 2
    parent2 = [-1, 0, 4, 0, 1]
    s2 = "abbba"
    print(f"Result of test case 2 : {sol.findSubtreeSizes(parent2, s2)}") # Expected: {5, 2, 1, 1, 1}
