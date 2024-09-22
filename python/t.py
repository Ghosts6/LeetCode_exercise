class Solution:
    def findKthNumber(self, n: int, k: int) -> int:
        def countSteps(curr, n):
            steps = 0
            first = curr
            last = curr
            while first <= n:
                steps += min(n + 1, last + 1) - first
                first *= 10
                last = last * 10 + 9
            return steps
        
        curr = 1
        k -= 1  
        while k > 0:
            steps = countSteps(curr, n)
            if steps <= k:
                k -= steps
                curr += 1
            else:
                curr *= 10
                k -= 1  
        return curr

# Test cases
solution = Solution()
# case 1
print(solution.findKthNumber(13, 2))  # Output: 10
# case 2
print(solution.findKthNumber(1, 1))   # Output: 1
