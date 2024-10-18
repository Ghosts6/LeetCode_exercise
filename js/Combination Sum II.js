var combinationSum2 = function(candidates, target) {
    let result = [];  
    candidates.sort((a, b) => a - b); 
    backtrack(candidates, target, 0, [], result);
    return result;
};

function backtrack(candidates, target, start, combination, result) {
    if (target === 0) { 
        result.push([...combination]);
        return;
    }

    for (let i = start; i < candidates.length; i++) {
        if (i > start && candidates[i] === candidates[i - 1]) {
            continue;
        }

        if (candidates[i] > target) {  
            break;
        }

        combination.push(candidates[i]);  
        backtrack(candidates, target - candidates[i], i + 1, combination, result); 
        combination.pop(); 
    }
}

// Test cases
console.log("Example 1 Output:", combinationSum2([10, 1, 2, 7, 6, 1, 5], 8)); // Expected: [[1,1,6], [1,2,5], [1,7], [2,6]]


console.log("Example 2 Output:", combinationSum2([2, 5, 2, 1, 2], 5)); // Expected: [[1,2,2], [5]]
