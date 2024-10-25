var combinationSum3 = function(k, n) {
    let result = [];
    
    function backtrack(target, start, combination) {
        if (target === 0 && combination.length === k) {
            result.push([...combination]);  
            return;
        }

        for (let i = start; i <= 9; i++) {
            if (i > target) {
                break; 
            }

            combination.push(i);
            backtrack(target - i, i + 1, combination);
            combination.pop(); 
        }
    }
    
    backtrack(n, 1, []);
    return result;
};

console.log(combinationSum3(k = 3, n = 7))
console.log(combinationSum3(k = 3, n = 9))
console.log(combinationSum3(k = 4, n = 1))
