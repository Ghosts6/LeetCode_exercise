from bisect import bisect_left

class Solution:
    def findRightInterval(self, intervals):
        starts = sorted((interval[0], i) for i, interval in enumerate(intervals))

        result = []

        for interval in intervals:
            end = interval[1]

            idx = bisect_left(starts, (end,))

            if idx < len(starts):
                result.append(starts[idx][1])
            else:
                result.append(-1)
        
        return result

# Test cases
if __name__ == "__main__":
    # Case 1
    intervals1 = [[1, 2]]
    solution = Solution()
    print(solution.findRightInterval(intervals1))  # Output: [-1]
    
    # Case 2
    intervals2 = [[3, 4], [2, 3], [1, 2]]
    print(solution.findRightInterval(intervals2))  # Output: [-1, 0, 1]
    
    # Case 3 
    intervals3 = [[1, 4], [2, 3], [3, 4]]
    print(solution.findRightInterval(intervals3))  # Output: [-1, 2, -1]
