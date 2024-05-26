class Solution(object):
    def isValidSudoku(self, board):
        rows = [set() for _ in range(9)]
        cols = [set() for _ in range(9)]
        boxes = [set() for _ in range(9)]

        for i in range(9):
            for j in range(9):
                current = board[i][j]
                if current == '.':
                    continue
                if current in rows[i] or current in cols[j] or current in boxes[(i // 3) * 3 + j // 3]:
                    return False
                rows[i].add(current)
                cols[j].add(current)
                boxes[(i // 3) * 3 + j // 3].add(current)

        return True