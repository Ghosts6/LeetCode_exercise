class Solution:
    def minOperations(self, nums: list[int], k: int) -> int:
        """
        Returns the minimum number of operations to make all elements in nums equal to k,
        using the allowed reduction operations. Returns -1 if impossible.
        """
        if any(num < k for num in nums):
            return -1
        
        unique = sorted(set(num for num in nums if num > k), reverse=True)
        
        operations = 0
        prev = float('inf')
        
        for num in unique:
            if num < prev:
                operations += 1
                prev = num
        
        return operations

# Test cases
if __name__ == "__main__":
    solution = Solution()
    # case 1
    nums1 = [5,2,5,4,5]
    k1 = 2
    print(f"result of test case 1 : {solution.minOperations(nums1, k1)}") # Expected Output: 2

    # case 2
    nums2 = [2,1,2]
    k2 = 2
    print(f"result of test case 2 : {solution.minOperations(nums2, k2)}") # Expected Output: -1

    # case 3
    nums3 = [9,7,5,3]
    k3 = 1
    print(f"result of test case 3 : {solution.minOperations(nums3, k3)}") # Expected Output: 4