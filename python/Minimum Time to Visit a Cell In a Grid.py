from typing import List

class MinHeap:
    def __init__(self):
        self.heap = []
    
    def push(self, element):
        self.heap.append(element)
        self._sift_up(len(self.heap) - 1)
    
    def pop(self):
        if len(self.heap) == 1:
            return self.heap.pop()
        root = self.heap[0]
        self.heap[0] = self.heap.pop()
        self._sift_down(0)
        return root
    
    def _sift_up(self, idx):
        parent = (idx - 1) // 2
        while idx > 0 and self.heap[idx][0] < self.heap[parent][0]:
            self.heap[idx], self.heap[parent] = self.heap[parent], self.heap[idx]
            idx = parent
            parent = (idx - 1) // 2
    
    def _sift_down(self, idx):
        n = len(self.heap)
        while idx * 2 + 1 < n:
            smallest = idx
            left = idx * 2 + 1
            right = idx * 2 + 2
            if left < n and self.heap[left][0] < self.heap[smallest][0]:
                smallest = left
            if right < n and self.heap[right][0] < self.heap[smallest][0]:
                smallest = right
            if smallest == idx:
                break
            self.heap[idx], self.heap[smallest] = self.heap[smallest], self.heap[idx]
            idx = smallest

    def is_empty(self):
        return len(self.heap) == 0


class Solution:
    def minimumTime(self, grid: List[List[int]]) -> int:
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        
        if grid[0][1] > 1 and grid[1][0] > 1:
            return -1
        
        m, n = len(grid), len(grid[0])
        heap = MinHeap()
        heap.push((0, 0, 0))
        visited = [[False] * n for _ in range(m)]
        
        while not heap.is_empty():
            time, row, col = heap.pop()
            
            if row == m - 1 and col == n - 1:
                return time
            
            if visited[row][col]:
                continue
            visited[row][col] = True
            
            for dr, dc in directions:
                r, c = row + dr, col + dc
                if 0 <= r < m and 0 <= c < n and not visited[r][c]:
                    if grid[r][c] <= time + 1:
                        heap.push((time + 1, r, c))
                    else:
                        diff = grid[r][c] - time
                        heap.push((grid[r][c] if diff % 2 == 1 else grid[r][c] + 1, r, c))
        
        return -1


# Test cases 
if __name__ == "__main__":
    solution = Solution()
    
    # case 1
    grid1 = [[0,1,3,2],[5,1,2,5],[4,3,8,6]]
    print("Output for grid1:", solution.minimumTime(grid1))  # Expected: 7
    
    # case 2
    grid2 = [[0,2,4],[3,2,1],[1,0,4]]
    print("Output for grid2:", solution.minimumTime(grid2))  # Expected: -1