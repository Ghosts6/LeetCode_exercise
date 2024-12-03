function countDigits(num) {
    let count = 0;
    let originalNum = num;
    
    while (num > 0) {
        let digit = num % 10;
        num = Math.floor(num / 10);
        
        // Avoid division by zero
        if (digit !== 0 && originalNum % digit === 0) {
            count++;
        }
    }
    
    return count;
}

// Test cases
console.log(countDigits(7));    // Output: 1
console.log(countDigits(121));  // Output: 2
console.log(countDigits(1248)); // Output: 4
