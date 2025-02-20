var clearDigits = function(s) {
    let stack = [];
    for (let c of s) {
        if (/\d/.test(c)) {
            if (stack.length > 0) stack.pop();
        } else {
            stack.push(c);
        }
    }
    return stack.join('');
}
// Test case
console.log(clearDigits("abc")) // Expected out put: abc
console.log(clearDigits("cb34")) // Expected out put: 
