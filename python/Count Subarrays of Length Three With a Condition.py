class Solution:
    def countSubarrays(self, nums: list[int]) -> int:
        """
        Returns the number of valid triplets in the array where the sum of the first and third elements 
        equals exactly half of the second element.
        """
        count = 0
        for i in range(1, len(nums) - 1):
            if nums[i] == 2 * (nums[i - 1] + nums[i + 1]):
                count += 1
        return count
    
# Test cases
if __name__ == "__main__":
    solution = Solution()

    # case 1
    nums1 = [1,2,1,4,1]
    print(f"result of test case 1 : {solution.countSubarrays(nums1)}") # Expected Output: 1

    # case 2
    nums2 = [1,1,1]
    print(f"result of test case 2 : {solution.countSubarrays(nums2)}") # Expected Output: 0