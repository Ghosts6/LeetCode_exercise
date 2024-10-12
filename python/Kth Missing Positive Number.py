class Solution:
    def findKthPositive(self, arr, k):
        missing_count = 0
        current = 1
        i = 0  

        while missing_count < k:
            if i < len(arr) and arr[i] == current:
                i += 1
            else:
                missing_count += 1
            current += 1

        return current - 1

# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # case 1
    arr1 = [2, 3, 4, 7, 11]
    k1 = 5
    result1 = solution.findKthPositive(arr1, k1)
    print(f"Test case 1: Expected Output = 9, Got = {result1}")
    
    # case 2
    arr2 = [1, 2, 3, 4]
    k2 = 2
    result2 = solution.findKthPositive(arr2, k2)
    print(f"Test case 2: Expected Output = 6, Got = {result2}")
    
    # Additional cases
    arr3 = [5, 6, 7, 8]
    k3 = 4
    result3 = solution.findKthPositive(arr3, k3)
    print(f"Test case 3: Expected Output = 4, Got = {result3}")
    
    arr4 = [1, 3, 5, 7]
    k4 = 3
    result4 = solution.findKthPositive(arr4, k4)
    print(f"Test case 4: Expected Output = 6, Got = {result4}")
