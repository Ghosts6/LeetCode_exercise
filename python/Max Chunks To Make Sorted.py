class Solution:
    def maxChunksToSorted(self, arr):
        max_seen = 0
        chunks = 0

        for i, value in enumerate(arr):
            max_seen = max(max_seen, value)
            if max_seen == i:
                chunks += 1

        return chunks
# Test cases
if __name__ == "__main__":
    solution = Solution()
  
    # case 1
    arr1 = [4, 3, 2, 1, 0]
    print("Example 1 Output:", solution.maxChunksToSorted(arr1))  # Output: 1

    # case 2
    arr2 = [1, 0, 2, 3, 4]
    print("Example 2 Output:", solution.maxChunksToSorted(arr2))  # Output: 4
