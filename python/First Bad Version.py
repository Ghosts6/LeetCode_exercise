# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        low, high = 1, n
        
        while low < high:
            mid = (low + high) // 2  
            if isBadVersion(mid):
                high = mid  
            else:
                low = mid + 1 
        
        return low 

# Test cases
if __name__ == "__main__":
    def isBadVersion(version: int) -> bool:
        return version >= 4 
    
    solution = Solution()
    
    # cases
    print(solution.firstBadVersion(5))  # Output  4
    print(solution.firstBadVersion(1))  # Output  1
