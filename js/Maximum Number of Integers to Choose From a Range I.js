var maxCount = function(banned, n, maxSum) {
    banned.sort((a, b) => a - b);

    let sum = 0, count = 0;

    for (let i = 1; i <= n; i++) {
        if (isBanned(banned, i)) continue;

        if (sum + i > maxSum) break;

        sum += i;
        count++;
    }

    return count;
};
function isBanned(banned, x) {
    let left = 0, right = banned.length - 1;

    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        if (banned[mid] === x) return true;
        if (banned[mid] < x) left = mid + 1;
        else right = mid - 1;
    }

    return false;
}
// Test cases
console.log(maxCount([1, 6, 5], 5, 6)); // Output: 2
console.log(maxCount([1, 2, 3, 4, 5, 6, 7], 8, 1)); // Output: 0
console.log(maxCount([11], 7, 50)); // Output: 7

