var minSwaps = function (s) {
    let imbalance = 0;
    let maxImbalance = 0;

    for (let char of s) {
        if (char === '[') {
            imbalance--;
        } else {
            imbalance++;
        }
        maxImbalance = Math.max(maxImbalance, imbalance);
    }

    return Math.ceil(maxImbalance / 2);
}

// Test cases

// case 1
let s1 = "][][";
console.log(minSwaps(s1)); // Expected output: 1

// case 2
let s2 = "]]][[[";
console.log(minSwaps(s2)); // Expected output: 2

// Additional case: already balanced
let s3 = "[[]]";
console.log(minSwaps(s3)); // Expected output: 0



