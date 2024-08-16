class Solution:
    def maxDistance(self, arrays):
        global_min = arrays[0][0]
        global_max = arrays[0][-1]

        max_distance = 0

        for array in arrays[1:]:
            curr_min = array[0]
            curr_max = array[-1]

            max_distance = max(max_distance, abs(global_max - curr_min), abs(global_min - curr_max))

            global_min = min(global_min, curr_min)
            global_max = max(global_max, curr_max)
        
        return max_distance

# Test cases
solution = Solution()

# case 1
arrays1 = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
print(solution.maxDistance(arrays1))  

# case 2
arrays2 = [[1, 3, 5], [2, 4, 6], [7, 8, 9]]
print(solution.maxDistance(arrays2))  


