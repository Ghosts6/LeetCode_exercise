class Solution:
    def search(self, nums: list[int], target: int) -> int:
        low, high = 0, len(nums) - 1

        while low <= high:
            mid = low + (high - low) // 2  
            
            if nums[mid] == target:  
                return mid
            elif nums[mid] < target:  
                low = mid + 1
            else:  
                high = mid - 1

        return -1

# Test cases
if __name__ == "__main__":
    # case 1
    nums1 = [-1, 0, 3, 5, 9, 12]
    target1 = 9
    solution = Solution()
    print(solution.search(nums1, target1))  # Output: 4

    # case 2
    nums2 = [-1, 0, 3, 5, 9, 12]
    target2 = 2
    print(solution.search(nums2, target2))  # Output: -1