# 📜 Successful Pairs of Spells and Potions


## 💡 Intuition
The problem requires finding how many successful pairs can be formed by multiplying each spell with a potion such that the product is greater than or equal to a given success threshold. To efficiently solve this, we can leverage sorting and binary search to quickly count the number of valid potions for each spell.

## 🛠️ Approach
1.  Sort the Potions Array: By sorting the potions array, we enable efficient searching. For each spell, the problem then reduces to finding the first potion that, when multiplied by the spell, meets or exceeds the success threshold.

2.  Binary Search for Valid Potions:
For each spell, calculate the minimum potion strength needed to form a successful pair by dividing success by the spell.
Use binary search to find the first potion in the sorted array that is equal to or greater than this calculated value.
The count of successful pairs for that spell is simply the number of potions from this index to the end of the array.

3.  Result Storage: Store the count of valid potions for each spell in a result array, which is then returned.

## ⏰ Complexity
- Time complexity:O(m log m + n log m)


- Space complexity:O(n)


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