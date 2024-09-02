class Solution:
    def eraseOverlapIntervals(self, intervals):
        if not intervals:
            return 0

        intervals.sort(key=lambda x: x[1])

        end = intervals[0][1]
        count = 0

        for i in range(1, len(intervals)):
            if intervals[i][0] < end:
                count += 1
            else:
                end = intervals[i][1]
        
        return count

# Test cases
solution = Solution()

# case 1
intervals1 = [[1, 2], [2, 3], [3, 4], [1, 3]]
print(solution.eraseOverlapIntervals(intervals1))  # Expected Output: 1

# case 2
intervals2 = [[1, 2], [1, 2], [1, 2]]
print(solution.eraseOverlapIntervals(intervals2))  # Expected Output: 2

# case 3
intervals3 = [[1, 2], [2, 3]]
print(solution.eraseOverlapIntervals(intervals3))  # Expected Output: 0
