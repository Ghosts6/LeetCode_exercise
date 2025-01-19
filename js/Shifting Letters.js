var shiftingLetters = function(s, shifts) {
    var n = s.length;
    var totalShift = 0;
    var result = s.split('');
    
    for (var i = n - 1; i >= 0; i--) {
        totalShift += shifts[i];
        totalShift %= 26; 
        result[i] = String.fromCharCode((s.charCodeAt(i) - 'a'.charCodeAt(0) + totalShift) % 26 + 'a'.charCodeAt(0));
    }
    
    return result.join('');
};

// Test cases
console.log(shiftingLetters("abc", [3, 5, 9])); // Expected Output: "rpl"
console.log(shiftingLetters("aaa", [1, 2, 3])); // Expected Output: "gfd"
