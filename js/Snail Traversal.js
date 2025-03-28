Array.prototype.snail = function(rowsCount, colsCount) {
    if (rowsCount * colsCount !== this.length) return [];

    const result = Array.from({ length: rowsCount }, () => []);
    let index = 0;

    for (let col = 0; col < colsCount; col++) {
        if (col % 2 === 0) {
            for (let row = 0; row < rowsCount; row++) {
                result[row][col] = this[index++];
            }
        } else {
            for (let row = rowsCount - 1; row >= 0; row--) {
                result[row][col] = this[index++];
            }
        }
    }
    
    return result;
};

// Test cases
console.log([19, 10, 3, 7, 9, 8, 5, 2, 1, 17, 16, 14, 12, 18, 6, 13, 11, 20, 4, 15].snail(5, 4));
console.log([1, 2, 3, 4].snail(1, 4));
console.log([1, 3].snail(2, 2));
