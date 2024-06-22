from typing import List

class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        highest_altitude = 0
        current_altitude = 0
        
        for g in gain:
            current_altitude += g
            highest_altitude = max(highest_altitude, current_altitude)
        
        return highest_altitude

# test case
if __name__ == "__main__":
    solution = Solution()
    
    gain = [-5, 1, 5, 0, -7]
    result = solution.largestAltitude(gain)
    
    print("highest altitude reached:", result)  
