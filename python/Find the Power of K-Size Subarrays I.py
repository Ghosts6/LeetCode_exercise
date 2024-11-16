class Solution:
    def resultsArray(self, nums, k):
        results = []
        n = len(nums)

        for i in range(n - k + 1):
            subarray = nums[i:i + k]
            if sorted(subarray) == list(range(min(subarray), max(subarray) + 1)):
                results.append(max(subarray))  
            else:
                results.append(-1) 

        return results


# Test cases
if __name__ == "__main__":
    solution = Solution()

    # case 1
    nums1 = [1, 2, 3, 4, 3, 2, 5]
    k1 = 3
    print("Test case 1:", solution.resultsArray(nums1, k1))

    # case 2
    nums2 = [2, 2, 2, 2, 2]
    k2 = 4
    print("Test case 2:", solution.resultsArray(nums2, k2))

    # case 3
    nums3 = [3, 2, 3, 2, 3, 2]
    k3 = 2
    print("Test case 3:", solution.resultsArray(nums3, k3))
