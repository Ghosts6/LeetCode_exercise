# 📜 Successful Pairs of Spells and Potions

## 💡 Intuition
The problem requires finding pairs of *spells* and *potions* such that the product of each pair meets or exceeds a given `success` threshold. We need to determine the number of valid potions for each spell efficiently to minimize time complexity. 

This approach combines sorting and binary search to quickly count valid pairs:

1. **Sorting the Potions Array**: Sorting allows us to apply binary search on the potions, enabling efficient lookups for the minimum required potion strength.
2. **Binary Search**: For each spell, calculate the minimum potion strength needed to reach the `success` threshold. Using binary search, find the index of the first potion meeting this strength in the sorted potions array.
3. **Counting Valid Pairs**: The number of successful pairs for a given spell is the count of potions from the found index to the end of the array.



## 🛠️ Approach
1. **Sort the Potions Array**: By sorting the `potions` array, the task of finding the first valid potion (i.e., the smallest potion that can create a successful pair) becomes efficient.
   
2. **Calculate Minimum Required Strength**: For each spell, calculate the required minimum strength for the potion as `minPotionStrength = success / spell`. This gives the threshold potion strength that must be met or exceeded.
   
3. **Binary Search for Valid Potions**: Perform a binary search on the sorted `potions` array to find the index of the first potion that meets or exceeds `minPotionStrength`. The count of valid potions is simply the number of potions from this index onward.

4. **Store the Result**: Record the count of valid potions for each spell in a `result` array.



## ⏰ Complexity
- **Time Complexity**: \(O(m \log m + n \log m)\) where \(m\) is the length of `potions` and \(n\) is the length of `spells`. Sorting the `potions` array takes \(O(m \log m)\), and for each spell, we perform a binary search which takes \(O(\log m)\).
- **Space Complexity**: \(O(n)\) for storing the results for each spell.




## 💻 Code
```python []
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

```
```C []
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int binarySearch(int* potions, int potionsSize, long long minPotionStrength) {
    int left = 0, right = potionsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (potions[mid] >= minPotionStrength) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize, long long success, int* returnSize) {
    qsort(potions, potionsSize, sizeof(int), compare);
    
    int* result = (int*)malloc(spellsSize * sizeof(int));

    for (int i = 0; i < spellsSize; i++) {
        long long minPotionStrength = (success + spells[i] - 1) / spells[i];
        
        int index = binarySearch(potions, potionsSize, minPotionStrength);
       
        result[i] = potionsSize - index;
    }

    *returnSize = spellsSize;
    
    return result;
}
```
```c++ []
class Solution {
public:
    std::vector<int> successfulPairs(std::vector<int>& spells, std::vector<int>& potions, long long success) {
        std::sort(potions.begin(), potions.end());
        int m = potions.size();
        std::vector<int> result;
        
        for (int spell : spells) {
            long long min_potion_strength = (success + spell - 1) / spell;
            int index = std::lower_bound(potions.begin(), potions.end(), min_potion_strength) - potions.begin();
            result.push_back(m - index);
        }
        
        return result;
    }
};
```