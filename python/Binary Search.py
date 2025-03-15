class Solution:
    def search(self, nums: list[int], target: int) -> int:
        """
        Returns the index of the target element in the given list of integers. If the target element is not found, returns -1.
        Algorithm: Binary Search
        """
        low, high = 0, len(nums) - 1

        while low <= high:
            mid = (low + high) // 2  

            if nums[mid] == target:
                return mid
            if nums[mid] < target:
                low = mid + 1
            else:
                high = mid - 1

        return -1

# Test cases
if __name__ == "__main__":
    solution = Solution()

    # case 1
    nums1 = [-1, 0, 3, 5, 9, 12]
    target1 = 9
    print(f"result for {nums1} and target {target1} is : {solution.search(nums1, target1)}")  # Expected Output: 4

    # case 2
    nums2 = [-1, 0, 3, 5, 9, 12]
    target2 = 2
    print(f"result for {nums2} and target {target2} is : {solution.search(nums2, target2)}")  # Expected Output: -1