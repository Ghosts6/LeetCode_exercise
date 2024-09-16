from typing import List

class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        def convertToMinutes(time: str) -> int:
            hours, minutes = map(int, time.split(":"))
            return hours * 60 + minutes

        minutes_list = [convertToMinutes(time) for time in timePoints]

        minutes_list.sort()

        min_diff = float('inf')
       
        for i in range(1, len(minutes_list)):
            min_diff = min(min_diff, minutes_list[i] - minutes_list[i - 1])

        min_diff = min(min_diff, 1440 + minutes_list[0] - minutes_list[-1])
        
        return min_diff

# Test cases
if __name__ == "__main__":
    sol = Solution()
    
    # case 1
    timePoints1 = ["23:59", "00:00"]
    print(sol.findMinDifference(timePoints1))  # Output: 1
    
    # case 2
    timePoints2 = ["00:00", "23:59", "00:00"]
    print(sol.findMinDifference(timePoints2))  # Output: 0
    
    # case 3 
    timePoints3 = ["12:30", "23:59", "00:01", "05:45"]
    print(sol.findMinDifference(timePoints3))  # Output: 2
    

