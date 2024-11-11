var getMaximumXor = function (nums, maximumBit) {
    const n = nums.length;
    let totalXor = 0;

    for (let num of nums) {
        totalXor ^= num;
    }

    const mask = (1 << maximumBit) - 1; 
    const answer = new Array(n);

    for (let i = 0; i < n; i++) {
        answer[i] = totalXor ^ mask;
        totalXor ^= nums[n - 1 - i];
    }

    return answer;
}
// Test case
console.log(getMaximumXor( [0,1,1,3] , 2 ));
console.log(getMaximumXor( [2,3,4,7] , 3 ));
console.log(getMaximumXor( [0,1,2,2,5,7] , 3 ));