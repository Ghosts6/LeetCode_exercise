class Solution:
    def minOperations(self, nums: list[int]) -> int:
        """
        Returns the minimum number of operations to make all elements in nums equal to 1.
        Each operation flips 3 consecutive elements in the array. If it's impossible, returns -1.
        """
        n = len(nums)
        operations = 0

        for i in range(n - 2):
            if nums[i] == 0:
                nums[i] ^= 1
                nums[i + 1] ^= 1
                nums[i + 2] ^= 1
                operations += 1

        return operations if all(num == 1 for num in nums) else -1

# Test cases
if __name__ == "__main__":
    solution = Solution()
    # case 1
    nums1 = [0, 1, 1, 1, 0, 0]
    print(f"Test case 1 : {solution.minOperations(nums1)}") # Expected Output: 3

    # case 2
    nums2 = [0,1,1,1]
    print(f"Test case 2 : {solution.minOperations(nums2)}") # Expected Output: -1
