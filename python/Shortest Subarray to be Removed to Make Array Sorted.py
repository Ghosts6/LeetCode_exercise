class Solution:
    def findLengthOfShortestSubarray(self, arr):
        n = len(arr)
        left = 0
        right = n - 1

        while left < n - 1 and arr[left] <= arr[left + 1]:
            left += 1

        if left == n - 1:
            return 0

        while right > 0 and arr[right - 1] <= arr[right]:
            right -= 1
        
        result = min(n - left - 1, right)

        i, j = 0, right
        while i <= left and j < n:
            if arr[i] <= arr[j]:
                result = min(result, j - i - 1)
                i += 1
            else:
                j += 1
        
        return result

if __name__ == "__main__":
    solution = Solution()
    # Case 1
    arr1 = [1, 2, 3, 10, 4, 2, 3, 5]
    print(f"Test Case 1: {arr1}","Output:", solution.findLengthOfShortestSubarray(arr1))
    # Case 2
    arr2 = [5, 4, 3, 2, 1]
    print(f"Test Case 2: {arr2}","Output:", solution.findLengthOfShortestSubarray(arr2))
    # Case 3
    arr3 = [1, 2, 3]
    print(f"Test Case 3: {arr3}","Output:", solution.findLengthOfShortestSubarray(arr3))


