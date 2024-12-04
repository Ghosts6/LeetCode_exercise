var canMakeSubsequence = function (str1, str2) {
    if (str2.length > str1.length) return false;
    let j = 0; 

    for (let i = 0; i < str1.length; i++) {
        if (str1[i] === str2[j] || (str1[i] === String.fromCharCode((str2[j].charCodeAt(0) - 97 - 1 + 26) % 26 + 97))) {
            j++; 
        }
        if (j === str2.length) return true;
    }
    return false;
}

// Test cases
console.log(canMakeSubsequence("abc", "ad")); // true
console.log(canMakeSubsequence("zc", "ad"));  // true
console.log(canMakeSubsequence("ab", "d"));   // false

