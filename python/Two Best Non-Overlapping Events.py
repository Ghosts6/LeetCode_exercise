from sortedcontainers import SortedList

class Solution:
    def maxTwoEvents(self, events):
        events.sort(key=lambda x: x[1])
        max_result = 0
        sorted_list = SortedList()
        
        for start, end, value in events:
            max_val_before = 0
            idx = sorted_list.bisect_right((start - 1, float('inf')))
            if idx > 0:
                max_val_before = sorted_list[idx - 1][1]
            max_result = max(max_result, max_val_before + value)
            if not sorted_list or value > sorted_list[-1][1]:
                sorted_list.add((end, max(max_val_before, value)))
        
        return max_result
# Test cases
if __name__ == "__main__":
    solution = Solution()
    # case 1
    events = [[1,3,2],[4,5,2],[2,4,3]]
    print(solution.maxTwoEvents(events))  # Expected Output: 4
    # case 2
    events = [[1,3,2],[4,5,2],[1,5,5]]
    print(solution.maxTwoEvents(events))  # Expected Output: 5
    # case 3
    events = [[1,5,3],[1,5,1],[6,6,5]]
    print(solution.maxTwoEvents(events))  # Expected Output: 8
