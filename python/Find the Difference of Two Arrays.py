from typing import List

class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        set1, set2 = set(nums1), set(nums2)
        
        res1 = list(set1 - set2)
        res2 = list(set2 - set1)
        
        return [res1, res2]

# test case
if __name__ == "__main__":
    solution = Solution()
    
    nums1 = [1, 2, 3]
    nums2 = [2, 4, 6]
    result = solution.findDifference(nums1, nums2)
    
    print("result of test case number 1:", result[0])  
    print("result of test case number 2:", result[1])  
