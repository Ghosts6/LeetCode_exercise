class Solution:
    def nextGreatestLetter(self, letters, target):
        left, right = 0, len(letters) - 1

        if target >= letters[right]:
            return letters[0]

        while left < right:
            mid = (left + right) // 2
            if letters[mid] > target:
                right = mid
            else:
                left = mid + 1
        
        return letters[left]
# Test cases
if __name__ == "__main__":
    sol = Solution()
    
    # Test case 1
    assert sol.nextGreatestLetter(["c", "f", "j"], "a") == "c"
    
    # Test case 2
    assert sol.nextGreatestLetter(["c", "f", "j"], "c") == "f"
    
    # Test case 3
    assert sol.nextGreatestLetter(["x", "x", "y", "y"], "z") == "x"
    
    print("All test cases passed!")