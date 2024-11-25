from collections import deque

class Solution:
    def slidingPuzzle(self, board):
        goal = (1, 2, 3, 4, 5, 0)
        
        start = tuple(board[0] + board[1])

        if start == goal:
            return 0
        
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        
        queue = deque([(start, start.index(0), 0)])  
        
        visited = set()
        visited.add(start)
        
        # BFS loop
        while queue:
            state, zero_pos, moves = queue.popleft()

            row, col = divmod(zero_pos, 3)
            
            for dr, dc in directions:
                new_row, new_col = row + dr, col + dc
                if 0 <= new_row < 2 and 0 <= new_col < 3:
                    new_zero_pos = new_row * 3 + new_col
                    new_state = list(state)
                    new_state[zero_pos], new_state[new_zero_pos] = new_state[new_zero_pos], new_state[zero_pos]
                    new_state = tuple(new_state)
                    
                    if new_state == goal:
                        return moves + 1
                    
                    if new_state not in visited:
                        visited.add(new_state)
                        queue.append((new_state, new_zero_pos, moves + 1))
        
        return -1

# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # case 1
    board1 = [[1, 2, 3], [4, 0, 5]]
    print(solution.slidingPuzzle(board1))  # Output: 1
    
    # case 2
    board2 = [[1, 2, 3], [5, 4, 0]]
    print(solution.slidingPuzzle(board2))  # Output: -1
    
    # case 3
    board3 = [[4, 1, 2], [5, 0, 3]]
    print(solution.slidingPuzzle(board3))  # Output: 5
