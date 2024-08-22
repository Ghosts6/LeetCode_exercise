from typing import List

class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        result = []
        combination = []
        self.backtrack(k, n, 1, combination, result)
        return result

    def backtrack(self, k: int, target: int, start: int, combination: List[int], result: List[List[int]]):
        if target == 0 and len(combination) == k:
            result.append(combination[:])  
            return

        for i in range(start, 10):
            if i > target:
                break
            
            combination.append(i)
            self.backtrack(k, target - i, i + 1, combination, result)
            combination.pop()  

# Test cases
if __name__ == "__main__":
    solution = Solution()
    k = 3
    n = 7
    print(solution.combinationSum3(k, n))  
    
    k = 3
    n = 9
    print(solution.combinationSum3(k, n))  