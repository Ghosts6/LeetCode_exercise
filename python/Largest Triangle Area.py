class Solution:
    def largestTriangleArea(self, points):
        def area(p1, p2, p3):
            return abs(p1[0]*(p2[1]-p3[1]) + p2[0]*(p3[1]-p1[1]) + p3[0]*(p1[1]-p2[1])) / 2
        n, ans = len(points), 0
        for i in range(n):
            for j in range(i+1, n):
                for k in range(j+1, n):
                    ans = max(ans, area(points[i], points[j], points[k]))
        return ans
# Test case
if __name__ == "__main__":
    sol = Solution()
    # case 1
    points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
    print(f"Result of test case 1 : {sol.largestTriangleArea(points)}") # Expected 2.00000
    
    # case 2
    points2 = [[1,0],[0,0],[0,1]]
    print(f"Result of test case 2 : {sol.largestTriangleArea(points2)}") # Expected 0.50000

