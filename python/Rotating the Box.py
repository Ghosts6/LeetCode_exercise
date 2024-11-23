class Solution:
    def rotateTheBox(self, box):
        m, n = len(box), len(box[0])

        for row in box:
            write_idx = n - 1  
            for col in range(n - 1, -1, -1):
                if row[col] == "#": 
                    row[col], row[write_idx] = ".", "#"
                    write_idx -= 1
                elif row[col] == "*":  
                    write_idx = col - 1

        rotated_box = [[None] * m for _ in range(n)]
        for i in range(m):
            for j in range(n):
                rotated_box[j][m - 1 - i] = box[i][j]
        
        return rotated_box


# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # case 1
    box1 = [["#", ".", "#"]]
    print("Input:", box1)
    print("Output:", solution.rotateTheBox(box1))
    
    #  case 2
    box2 = [["#", ".", "*", "."],
            ["#", "#", "*", "."]]
    print("\nInput:", box2)
    print("Output:", solution.rotateTheBox(box2))
    
    # case 3
    box3 = [["#", "#", "*", ".", "*", "."],
            ["#", "#", "#", "*", ".", "."],
            ["#", "#", "#", ".", "#", "."]]
    print("\nInput:", box3)
    print("Output:", solution.rotateTheBox(box3))
