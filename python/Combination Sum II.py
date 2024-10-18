class Solution:
    def combinationSum2(self, candidates, target):
        result = []  
        candidates.sort()  
        self.backtrack(candidates, target, 0, [], result)
        return result

    def backtrack(self, candidates, target, start, combination, result):
        if target == 0:  
            result.append(list(combination))
            return
        
        for i in range(start, len(candidates)):
            if i > start and candidates[i] == candidates[i - 1]: 
                continue
            
            if candidates[i] > target:  
                break
            
            combination.append(candidates[i])  
            self.backtrack(candidates, target - candidates[i], i + 1, combination, result) 
            combination.pop()  


# Test cases
if __name__ == "__main__":
    sol = Solution()

    # case 1
    candidates = [10, 1, 2, 7, 6, 1, 5]
    target = 8
    print("Example 1 Output:", sol.combinationSum2(candidates, target)) # Expected: [[1,1,6], [1,2,5], [1,7], [2,6]]
    

    # case 2
    candidates = [2, 5, 2, 1, 2]
    target = 5
    print("Example 2 Output:", sol.combinationSum2(candidates, target)) # Expected: [[1,2,2], [5]]
    