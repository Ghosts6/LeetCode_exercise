var subsetXORSum = function(nums) {
    let total = 0;
    const n = nums.length;
    const count = 1 << n;

    for (let i = 0; i < count; i++) {
        let xor = 0;
        for (let j = 0; j < n; j++) {
            if (i & (1 << j)) xor ^= nums[j];
        }
        total += xor;
    }

    return total;
}
// Test cases
console.log(subsetXORSum([1,3])); // Expected Output: 6
console.log(subsetXORSum([5,1,6])); // Expected Output: 20
console.log(subsetXORSum([3,4,5,6,7,8])); // Expected Output: 480