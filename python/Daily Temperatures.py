class Solution:
    def dailyTemperatures(self, temperatures):
        n = len(temperatures)
        answer = [0] * n
        stack = []

        for i in range(n):
            while stack and temperatures[i] > temperatures[stack[-1]]:
                prev_index = stack.pop()
                answer[prev_index] = i - prev_index
            stack.append(i)
        
        return answer

# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Case 1
    temperatures1 = [73, 74, 75, 71, 69, 72, 76, 73]
    output1 = solution.dailyTemperatures(temperatures1)
    print(f"Test Case 1 Result: {output1} (Expected: [1,1,4,2,1,1,0,0])")
    
    # Case 2
    temperatures2 = [30, 40, 50, 60]
    output2 = solution.dailyTemperatures(temperatures2)
    print(f"Test Case 2 Result: {output2} (Expected: [1,1,1,0])")
    
    # Case 3
    temperatures3 = [30, 60, 90]
    output3 = solution.dailyTemperatures(temperatures3)
    print(f"Test Case 3 Result: {output3} (Expected: [1,1,0])")
