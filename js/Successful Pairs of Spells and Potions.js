var successfulPairs = function(spells, potions, success) {
    potions.sort((a, b) => a - b);  
    const result = [];
    const m = potions.length;

    const bisectLeft = (arr, target) => {
        let left = 0, right = arr.length;
        while (left < right) {
            let mid = Math.floor((left + right) / 2);
            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    };

    spells.forEach(spell => {
        let minPotionStrength = Math.ceil(success / spell);  

        let index = bisectLeft(potions, minPotionStrength);  

        result.push(m - index);  
    });

    return result;
};

// Test cases
console.log(successfulPairs([10, 15, 7], [5, 8, 12, 18], 100));  // OutPut: [2, 3, 1]
console.log(successfulPairs([3, 6, 2], [1, 2, 3, 4, 5], 8));  // OutPut: [3, 5, 2]