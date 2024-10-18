class Solution:
    def peakIndexInMountainArray(self, arr):
        left, right = 0, len(arr) - 1  

        while left < right:
            mid = (left + right) // 2
            
            if arr[mid] > arr[mid + 1]:  
                right = mid
            else:  
                left = mid + 1
        
        return left  

# Test cases
if __name__ == "__main__":
    sol = Solution()

    # case 1
    arr1 = [0, 1, 0]
    print("Example 1 Output:", sol.peakIndexInMountainArray(arr1))  # Expected output: 1

    # case 2
    arr2 = [0, 2, 1, 0]
    print("Example 2 Output:", sol.peakIndexInMountainArray(arr2))  # Expected output: 1

    # case 3
    arr3 = [0, 10, 5, 2]
    print("Example 3 Output:", sol.peakIndexInMountainArray(arr3))  # Expected output: 1
