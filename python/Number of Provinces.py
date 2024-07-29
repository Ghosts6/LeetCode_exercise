class Solution:
    def findCircleNum(self, isConnected):
        n = len(isConnected)
        parent = list(range(n))
        rank = [1] * n

        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])  
            return parent[x]

        def union(x, y):
            rootX = find(x)
            rootY = find(y)
            if rootX != rootY:
                if rank[rootX] > rank[rootY]:
                    parent[rootY] = rootX
                elif rank[rootX] < rank[rootY]:
                    parent[rootX] = rootY
                else:
                    parent[rootY] = rootX
                    rank[rootX] += 1

        for i in range(n):
            for j in range(i + 1, n):
                if isConnected[i][j] == 1:
                    union(i, j)

        provinces = len({find(i) for i in range(n)})
        return provinces

# Test case
if __name__ == "__main__":
    solution = Solution()
    isConnected = [
        [1, 1, 0],
        [1, 1, 0],
        [0, 0, 1]
    ]
    result = solution.findCircleNum(isConnected)
    print(f"Number of provinces: {result}")
