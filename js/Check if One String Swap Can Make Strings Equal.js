const areAlmostEqual = function(s1, s2) {
    if (s1.length !== s2.length) return false;

    let diff = [];

    for (let i = 0; i < s1.length; ++i) {
        if (s1[i] !== s2[i]) {
            diff.push([s1[i], s2[i]]);
            if (diff.length > 2) return false;
        }
    }

    return diff.length === 0 || (diff.length === 2 && diff[0][0] === diff[1][1] && diff[0][1] === diff[1][0]);
};

// Test cases
console.log(areAlmostEqual("bank", "kanb")); // Expected Output: true
console.log(areAlmostEqual("attack", "defend")); // Expected Output: false
console.log(areAlmostEqual("kelb", "kelb")); // Expected Output: true

