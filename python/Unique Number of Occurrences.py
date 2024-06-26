from typing import List

class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        
        count_dict = {}
        for num in arr:
            count_dict[num] = count_dict.get(num, 0) + 1

        occurrences = set()
        for count in count_dict.values():
            if count in occurrences:
                return False
            occurrences.add(count)
        
        return True

# test cases
if __name__ == "__main__":
    solution = Solution()
    
    # accepted case
    arr = [1, 2, 2, 1, 1, 3]
    print("Test case 1 - Expected: True, Got:", solution.uniqueOccurrences(arr))  
    
    # fail case
    arr = [1, 2]
    print("Test case 2 - Expected: False, Got:", solution.uniqueOccurrences(arr))  
