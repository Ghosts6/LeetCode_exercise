from typing import List

class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        memo = {}
        
        def compute(expression: str) -> List[int]:
            if expression in memo:
                return memo[expression]
            
            results = []
            for i, char in enumerate(expression):
                if char in "+-*":
                    left_results = compute(expression[:i])
                    right_results = compute(expression[i+1:])
                    
                    for left in left_results:
                        for right in right_results:
                            if char == '+':
                                results.append(left + right)
                            elif char == '-':
                                results.append(left - right)
                            elif char == '*':
                                results.append(left * right)
            
            if not results:
                results = [int(expression)]
            
            memo[expression] = results
            return results
        
        return compute(expression)

# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # case 1
    expression1 = "2-1-1"
    result1 = solution.diffWaysToCompute(expression1)
    print(f"Expression: {expression1}, Possible Results: {result1}")
    # Output: [0, 2]
    
    # case 2
    expression2 = "2*3-4*5"
    result2 = solution.diffWaysToCompute(expression2)
    print(f"Expression: {expression2}, Possible Results: {result2}")
    # Output: [-34, -14, -10, -10, 10]
