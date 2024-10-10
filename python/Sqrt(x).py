class Solution:
    def mySqrt(self, x):
        if x == 0 or x == 1:
            return x
        left, right, ans = 1, x, 0
        while left <= right:
            mid = left + (right - left) // 2
            if mid <= x // mid:
                ans = mid
                left = mid + 1
            else:
                right = mid - 1
        return ans

# Test cases 
if __name__ == "__main__":
    solution = Solution()
    
    # case1
    x = 4
    print("Input:", x)
    print("Output:", solution.mySqrt(x))  # Expected output: 2
    
    # case 2
    x = 8
    print("Input:", x)
    print("Output:", solution.mySqrt(x))  # Expected output: 2

    # Additional 1
    x = 0
    print("Input:", x)
    print("Output:", solution.mySqrt(x))  # Expected output: 0

    # Additional Case 2
    x = 1
    print("Input:", x)
    print("Output:", solution.mySqrt(x))  # Expected output: 1

