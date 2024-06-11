from typing import List
from collections import defaultdict

class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        count_map = defaultdict(int)
        for num in arr1:
            count_map[num] += 1

        result = []
 
        for num in arr2:
            if num in count_map:
                result.extend([num] * count_map[num])
                del count_map[num]

        remaining_elements = sorted(count_map.items())
        for num, count in remaining_elements:
            result.extend([num] * count)
        
        return result

# test case
if __name__ == "__main__":
    arr1 = [2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19]
    arr2 = [2, 1, 4, 3, 9, 6]
    solution = Solution()
    sorted_arr = solution.relativeSortArray(arr1, arr2)
    print(f"Sorted array: {sorted_arr}")
