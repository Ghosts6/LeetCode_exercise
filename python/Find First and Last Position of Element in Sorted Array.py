class Solution:
    def searchRange(self, nums, target):
        def findStart(nums, target):
            left, right = 0, len(nums) - 1
            start = -1
            while left <= right:
                mid = left + (right - left) // 2
                if nums[mid] == target:
                    start = mid
                    right = mid - 1  
                elif nums[mid] < target:
                    left = mid + 1
                else:
                    right = mid - 1
            return start

        def findEnd(nums, target):
            left, right = 0, len(nums) - 1
            end = -1
            while left <= right:
                mid = left + (right - left) // 2
                if nums[mid] == target:
                    end = mid
                    left = mid + 1  
                elif nums[mid] < target:
                    left = mid + 1
                else:
                    right = mid - 1
            return end

        start = findStart(nums, target)
        end = findEnd(nums, target)
        return [start, end]
# Test cases
if __name__ == "__main__":
    sol = Solution()
    
    print(sol.searchRange([5, 7, 7, 8, 8, 10], 8))  
    print(sol.searchRange([5, 7, 7, 8, 8, 10], 6))  
    print(sol.searchRange([], 0))                    
