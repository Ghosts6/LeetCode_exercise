class Solution:
    def constructTransformedArray(self, nums: list[int]) -> list[int]:
        """Constructs a transformed array based on circular jumps defined by each element's value."""
        n = len(nums)
        return [nums[(i + nums[i]) % n] for i in range(n)]

# Test cases
if __name__ == "__main__":
    sol = Solution()

    # case 1
    nums1 = [3, -2, 1, 1]
    print(f"Result of test case 2 : {sol.constructTransformedArray(nums1)}") # Expected: 1,1,1,3

    # case 2
    nums2 = [-1, 4, -1]
    print(f"Result of test case 1 : {sol.constructTransformedArray(nums2)}") # Expected: -1,-1,4
