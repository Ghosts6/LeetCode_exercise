class Solution:
    def spiralMatrixIII(self, rows, cols, rStart, cStart):
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        result = []
        step = 0

        r, c = rStart, cStart
        direction_index = 0
        result.append([r, c])

        while len(result) < rows * cols:
            
            if direction_index == 0 or direction_index == 2:
                step += 1

            for _ in range(step):
                r += directions[direction_index][0]
                c += directions[direction_index][1]
                
                if 0 <= r < rows and 0 <= c < cols:
                    result.append([r, c])

            direction_index = (direction_index + 1) % 4

        return result

# Test case
if __name__ == "__main__":
    rows = 1
    cols = 4
    rStart = 0
    cStart = 0
    
    solution = Solution()
    result = solution.spiralMatrixIII(rows, cols, rStart, cStart)

    print(result)
