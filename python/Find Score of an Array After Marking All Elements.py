class Solution:
    def findScore(self, nums):
        n = len(nums)
        marked = [False] * n 
        score = 0

        elements = sorted((val, idx) for idx, val in enumerate(nums))

        for val, idx in elements:
            if not marked[idx]: 
                score += val
                marked[idx] = True
                if idx > 0:
                    marked[idx - 1] = True
                if idx < n - 1:
                    marked[idx + 1] = True

        return score
# Test cases
if __name__ == "__main__":
    solution = Solution()
    # case 1
    nums1 = [2, 1, 3, 4, 5, 2]
    print("Test case 1: ", solution.findScore(nums1))  # Output: 7

    # case 2
    nums2 = [2, 3, 5, 1, 3, 2]
    print("Test case 2: ", solution.findScore(nums2))  # Output: 5
