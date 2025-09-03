class Solution:
    def numberOfPairs(self, points: list[list[int]]) -> int:
        """Count valid upper-left pairs of points with empty rectangles or lines between them."""
        n = len(points)

        def is_blocked(a, b, c):
            # Check if c lies in or on the rectangle defined by a (upper-left) and b (lower-right)
            return min(a[0], b[0]) <= c[0] <= max(a[0], b[0]) and \
                   min(a[1], b[1]) <= c[1] <= max(a[1], b[1])

        count = 0
        for i in range(n):
            for j in range(n):
                ax, ay = points[i]
                bx, by = points[j]
                # A must be upper-left of B (left and above or equal to form line)
                if ax <= bx and ay >= by and (ax < bx or ay > by):
                    valid = True
                    for k in range(n):
                        if k != i and k != j and is_blocked(points[i], points[j], points[k]):
                            valid = False
                            break
                    if valid:
                        count += 1
        return count

# Test cases
if __name__ == "__main__":
    sol = Solution()

    points1 = [[1,1],[2,2],[3,3]]
    print("Result of test case 1:", sol.numberOfPairs(points1))  # Expected 0

    points2 = [[6,2],[4,4],[2,6]]
    print("Result of test case 2:", sol.numberOfPairs(points2))  # Expected 2

    points3 = [[3,1],[1,3],[1,1]]
    print("Result of test case 3:", sol.numberOfPairs(points3))  # Expected 2

