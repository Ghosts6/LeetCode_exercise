#include <stdio.h>
#include <stdlib.h>

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

// Test cases
int main() {
    int spells[] = {10, 20, 30};
    int potions[] = {1, 2, 3, 4, 5};
    long long success = 60;
    int spellsSize = sizeof(spells) / sizeof(spells[0]);
    int potionsSize = sizeof(potions) / sizeof(potions[0]);
    int returnSize;

    int* result = successfulPairs(spells, spellsSize, potions, potionsSize, success, &returnSize);

    printf("Successful pairs for each spell: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    
    free(result);

    return 0;
}
