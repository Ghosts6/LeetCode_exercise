var minimumSize = function (nums, maxOperations) {
    const isValid = (penalty) => {
        let operations = 0;
        for (const balls of nums) {
            operations += Math.ceil(balls / penalty) - 1; 
            if (operations > maxOperations) return false;
        }
        return true;
    };

    let left = 1; 
    let right = Math.max(...nums); 

    while (left < right) {
        const mid = Math.floor((left + right) / 2);
        if (isValid(mid)) {
            right = mid; 
        } else {
            left = mid + 1;
        }
    }

    return left;
}
// Test cases
console.log(minimumSize([9], 2)); // Output: 3
console.log(minimumSize([2, 4, 8, 2], 4)); // Output: 2
console.log(minimumSize([7, 17], 2)); // Output: 7
