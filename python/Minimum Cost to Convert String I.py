class Solution:
    def __init__(self):
        self.INF = float('inf')
        self.char_set = set('abcdefghijklmnopqrstuvwxyz')
        self.n = len(self.char_set)
        self.dist = {c: {c2: self.INF for c2 in self.char_set} for c in self.char_set}
        
    def initialize_distances(self, original, changed, cost):
        for c in self.char_set:
            self.dist[c][c] = 0
        for o, c, z in zip(original, changed, cost):
            self.dist[o][c] = min(self.dist[o][c], z)
    
    def floyd_warshall(self):
        for k in self.char_set:
            for i in self.char_set:
                for j in self.char_set:
                    if self.dist[i][k] < self.INF and self.dist[k][j] < self.INF:
                        self.dist[i][j] = min(self.dist[i][j], self.dist[i][k] + self.dist[k][j])
    
    def calculate_minimum_cost(self, source, target):
        total_cost = 0
        for s_char, t_char in zip(source, target):
            if self.dist[s_char][t_char] == self.INF:
                return -1  
            total_cost += self.dist[s_char][t_char]
        return total_cost

    def minimumCost(self, source, target, original, changed, cost):
        self.dist = {c: {c2: self.INF for c2 in self.char_set} for c in self.char_set}
        self.initialize_distances(original, changed, cost)
        self.floyd_warshall()
        return self.calculate_minimum_cost(source, target)

# Test case
source = "abcd"
target = "acbe"
original = ["a", "b", "c", "c", "e", "d"]
changed = ["b", "c", "b", "e", "b", "e"]
cost = [2, 5, 5, 1, 2, 20]

solution = Solution()
print(solution.minimumCost(source, target, original, changed, cost))

