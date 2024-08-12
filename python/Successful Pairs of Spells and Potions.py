from typing import List
import bisect

class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        potions.sort()
        result = []
        m = len(potions)
        
        for spell in spells:
            min_potion_strength = (success + spell - 1) // spell
            
            index = bisect.bisect_left(potions, min_potion_strength)

            result.append(m - index)
        
        return result

# Test Cases
def test_successful_pairs():
    solution = Solution()
    
    # Case 1
    spells = [10, 20, 30]
    potions = [1, 2, 3, 4, 5]
    success = 60
    assert solution.successfulPairs(spells, potions, success) == [3, 4, 5]
    
    # Case 2
    spells = [5, 1, 3]
    potions = [1, 2, 3, 4, 5]
    success = 7
    assert solution.successfulPairs(spells, potions, success) == [4, 0, 3]