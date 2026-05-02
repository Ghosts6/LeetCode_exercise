class Solution:
    def rotatedDigits(self, n: int) -> int:
        count = 0
        
        # Valid digits: 0, 1, 8, 2, 5, 6, 9
        # Digits that change the number: 2, 5, 6, 9
        # Digits that are invalid: 3, 4, 7
        
        for i in range(1, n + 1):
            s = str(i)
            if any(d in s for d in '347'):
                continue
            
            if any(d in s for d in '2569'):
                count += 1
                
        return count

# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # case 1
    n1 = 10
    print(solution.rotatedDigits(n1))  # Expected Output: 4
    
    # case 2
    n2 = 1
    print(solution.rotatedDigits(n2))  # Expected Output: 0
    
    # case 3
    n3 = 2
    print(solution.rotatedDigits(n3))  # Expected Output: 1
