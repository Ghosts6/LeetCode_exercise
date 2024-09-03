class Solution:
    def findMinArrowShots(self, points):
        if not points:
            return 0

        points.sort(key=lambda x: x[1])

        arrows = 1
        first_arrow_pos = points[0][1]
        
        for i in range(1, len(points)):
            if points[i][0] > first_arrow_pos:
                arrows += 1
                first_arrow_pos = points[i][1]
        
        return arrows

# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # case 1
    points1 = [[10,16],[2,8],[1,6],[7,12]]
    print("Test case 1 - Expected: 2, Got:", solution.findMinArrowShots(points1))
    
    # case 2
    points2 = [[1,2],[3,4],[5,6],[7,8]]
    print("Test case 2 - Expected: 4, Got:", solution.findMinArrowShots(points2))

