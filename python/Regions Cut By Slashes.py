class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [1] * n
        self.count = n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)
        
        if rootX != rootY:
            if self.rank[rootX] > self.rank[rootY]:
                self.parent[rootY] = rootX
            elif self.rank[rootX] < self.rank[rootY]:
                self.parent[rootX] = rootY
            else:
                self.parent[rootY] = rootX
                self.rank[rootX] += 1
            self.count -= 1

    def getCount(self):
        return self.count

class Solution:
    def regionsBySlashes(self, grid):
        n = len(grid)
        uf = UnionFind(4 * n * n)
        
        for i in range(n):
            for j in range(n):
                root = 4 * (i * n + j)
                char = grid[i][j]
                
                if char == '/':
                    uf.union(root + 0, root + 3) 
                    uf.union(root + 1, root + 2) 
                elif char == '\\':
                    uf.union(root + 0, root + 1)
                    uf.union(root + 2, root + 3) 
                else: 
                    uf.union(root + 0, root + 1) 
                    uf.union(root + 1, root + 2)
                    uf.union(root + 2, root + 3)
                  
                if j + 1 < n:  
                    uf.union(root + 1, 4 * (i * n + j + 1) + 3)
                if i + 1 < n:  
                    uf.union(root + 2, 4 * ((i + 1) * n + j) + 0)

        return uf.getCount()

# Test cases
solution = Solution()

# Test case 1
grid1 = [
    " /",
    "/ "
]
print(solution.regionsBySlashes(grid1)) 

# Test case 2
grid2 = [
    " /\\",
    " \\/",
    " \\/",
    " /\\"
]
print(solution.regionsBySlashes(grid2)) 
