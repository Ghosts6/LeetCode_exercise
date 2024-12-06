var maxCount = function(banned, n, maxSum) {
    const bannedSet = new Set(banned);
    let sum = 0;
    let count = 0;

    for (let i = 1; i <= n; i++) {
        if (bannedSet.has(i)) continue;
        if (sum + i > maxSum) break;
        sum += i;
        count++;
    }

    return count;
}

// Test cases
console.log(maxCount([1, 6, 5], 5, 6)); // Output: 2
console.log(maxCount([1, 2, 3, 4, 5, 6, 7], 8, 1)); // Output: 0
console.log(maxCount([11], 7, 50)); // Output: 7

