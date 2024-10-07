class Solution:
    def guessNumber(self, n: int) -> int:
        low, high = 1, n
        
        while low <= high:
            mid = low + (high - low) // 2
            result = guess(mid)
            
            if result == 0:
                return mid
            elif result == -1:
                high = mid - 1
            else: 
                low = mid + 1
        return -1

# v2 with bitwise 
# class Solution:
#     def guessNumber(self, n: int) -> int:
#         low, high = 1, n
        
#         while low <= high:
#             mid = (low + high) >> 1
#             result = guess(mid)
            
#             if result == 0:
#                 return mid
#             elif result == -1:
#                 high = mid - 1
#             else: 
#                 low = mid + 1

def guess(num: int) -> int:

    picked_number = 6
    if num < picked_number:
        return 1
    elif num > picked_number:
        return -1
    else:
        return 0

# Test case
solution = Solution()
print(solution.guessNumber(10)) 
