const countSymmetricIntegers = function (low, high) {
    let count = 0;

    for (let i = low; i <= high; i++) {
        const str = i.toString();
        if (str.length % 2 !== 0) continue;

        const mid = str.length / 2;
        let sum1 = 0, sum2 = 0;

        for (let j = 0; j < mid; j++) {
            sum1 += +str[j];
            sum2 += +str[j + mid];
        }

        if (sum1 === sum2) count++;
    }

    return count;
}

// Test case
console.log(countSymmetricIntegers(1, 200)); // Expected Output: 9
console.log(countSymmetricIntegers(1200, 1230)); // Expected Output: 4
