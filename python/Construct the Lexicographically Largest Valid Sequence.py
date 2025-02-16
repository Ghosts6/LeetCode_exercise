class Solution:
    def constructDistancedSequence(self, n: int):
        res = [0] * (2 * n - 1)
        used = [False] * (n + 1)

        def backtrack(index):
            if index == len(res):
                return True
            
            if res[index]:
                return backtrack(index + 1)
            
            for num in range(n, 0, -1):
                if used[num]:
                    continue
                if num == 1 or (index + num < len(res) and res[index + num] == 0):
                    res[index] = num
                    if num > 1:
                        res[index + num] = num
                    used[num] = True
                    
                    if backtrack(index + 1):
                        return True
                    
                    res[index] = 0
                    if num > 1:
                        res[index + num] = 0
                    used[num] = False
            
            return False

        backtrack(0)
        return res
  
# Test case
if __name__ == "__main__":
    solution = Solution()
    # case 1
    n1 = 3
    print(f"Output of test case 1: {solution.constructDistancedSequence(n1)}") # Expected Output: [3,1,2,3,2]
    # case 2
    n2 = 5
    print(f"Output of test case 2: {solution.constructDistancedSequence(n2)}") # Expected Output: [5,3,1,4,3,5,2,4,2]