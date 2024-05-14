function memoize(fn) {
    const cache = new Map();
    
    return function(...args) {
        const key = JSON.stringify(args);
        if (cache.has(key)) {
            return cache.get(key);
        } else {
            const result = fn(...args);
            cache.set(key, result);
            return result;
        }
    }
}

// test cases
let callCount = 0;
const memoizedSum = memoize(function(a, b) {
    callCount += 1;
    return a + b;
});

console.log(memoizedSum(2, 3)); 
console.log(memoizedSum(3, 2)); 
console.log(callCount); 

const memoizedFib = memoize(function(n) {
    return n <= 1 ? 1 : memoizedFib(n - 1) + memoizedFib(n - 2);
});

console.log(memoizedFib(5)); 

const memoizedFactorial = memoize(function(n) {
    return n <= 1 ? 1 : memoizedFactorial(n - 1) * n;
});

console.log(memoizedFactorial(5));
