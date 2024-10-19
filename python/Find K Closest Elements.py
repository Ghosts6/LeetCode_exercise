class Solution:
    def findClosestElements(self, arr, k, x):
        left = 0
        right = len(arr) - k
        
        while left < right:
            mid = (left + right) // 2
            if x - arr[mid] > arr[mid + k] - x:
                left = mid + 1
            else:
                right = mid

        return arr[left:left + k]

# Test cases 
if __name__ == "__main__":
    # case 1
    arr1 = [1, 2, 3, 4, 5]
    k1, x1 = 4, 3
    sol = Solution()
    result1 = sol.findClosestElements(arr1, k1, x1)
    print(f"Test case 1 - Expected: [1, 2, 3, 4], Got: {result1}")
    
    # case 2
    arr2 = [1, 1, 2, 3, 4, 5]
    k2, x2 = 4, -1
    result2 = sol.findClosestElements(arr2, k2, x2)
    print(f"Test case 2 - Expected: [1, 1, 2, 3], Got: {result2}")
    
    # Additional case
    arr3 = [1, 2, 3, 4, 5, 6, 7, 8]
    k3, x3 = 3, 6
    result3 = sol.findClosestElements(arr3, k3, x3)
    print(f"Test case 3 - Expected: [5, 6, 7], Got: {result3}")

