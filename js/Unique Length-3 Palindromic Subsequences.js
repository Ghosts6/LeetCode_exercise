var countPalindromicSubsequence = function(s) {
    let result = 0;
    const firstIndex = new Array(26).fill(-1);
    const lastIndex = new Array(26).fill(-1);
    
    for (let i = 0; i < s.length; i++) {
        let charIndex = s.charCodeAt(i) - 97;
        if (firstIndex[charIndex] === -1) firstIndex[charIndex] = i;
        lastIndex[charIndex] = i;
    }

    for (let i = 0; i < 26; i++) {
        if (firstIndex[i] < lastIndex[i]) {
            const uniqueChars = new Set();
            for (let j = firstIndex[i] + 1; j < lastIndex[i]; j++) {
                uniqueChars.add(s[j]);
            }
            result += uniqueChars.size;
        }
    }

    return result;
};
// Test cases
console.log(countPalindromicSubsequence("aabca")) // Expected: 
console.log(countPalindromicSubsequence("adc")) // Expected: 
console.log(countPalindromicSubsequence("bbcbaba")) // Expected: 