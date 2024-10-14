class Solution:
    def hIndex(self, citations):
        n = len(citations)
        left, right = 0, n - 1

        while left <= right:
            mid = (left + right) // 2
            if citations[mid] == n - mid:
                return n - mid
            elif citations[mid] < n - mid:
                left = mid + 1
            else:
                right = mid - 1

        return n - left

# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # case 1
    citations1 = [0, 1, 3, 5, 6]
    print("Output for citations [0, 1, 3, 5, 6]:", solution.hIndex(citations1))  # Expected output: 3
    
    # case 2
    citations2 = [1, 2, 100]
    print("Output for citations [1, 2, 100]:", solution.hIndex(citations2))  # Expected output: 2