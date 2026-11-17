from typing import List

class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        """Count contiguous subarrays with an odd sum."""
        MOD = 10**9 + 7

        odd = 0
        even = 1
        prefix = 0
        result = 0

        for num in arr:
            prefix += num

            if prefix % 2:
                result += even
                odd += 1
            else:
                result += odd
                even += 1

            result %= MOD

        return result

# Test case
if __name__ == "__main__":
    sol = Solution()

    # case 1
    arr1 = [1, 3, 5]
    print(f"Result of test case 1 : {sol.numOfSubarrays(arr1)}") # Expected: 4

    # case 2
    arr2 = [2, 4, 6]
    print(f"Result of test case 2 : {sol.numOfSubarrays(arr2)}") # Expected: 0

    # case 3
    arr3 = [1, 2, 3, 4, 5, 6, 7]
    print(f"Result of test case 3 : {sol.numOfSubarrays(arr3)}") # Expected: 16
