var checkInclusion = function (s1, s2) {
    const len1 = s1.length, len2 = s2.length;
    if (len1 > len2) return false;  

    const countS1 = Array(26).fill(0);
    const countWindow = Array(26).fill(0);

    for (let i = 0; i < len1; i++) {
        countS1[s1.charCodeAt(i) - 'a'.charCodeAt(0)]++;
        countWindow[s2.charCodeAt(i) - 'a'.charCodeAt(0)]++;
    }

    if (arraysEqual(countS1, countWindow)) return true;

    for (let i = len1; i < len2; i++) {
        countWindow[s2.charCodeAt(i) - 'a'.charCodeAt(0)]++;
        countWindow[s2.charCodeAt(i - len1) - 'a'.charCodeAt(0)]--;
        if (arraysEqual(countS1, countWindow)) return true;
    }

    return false;
}

function arraysEqual(arr1, arr2) {
    for (let i = 0; i < 26; i++) {
        if (arr1[i] !== arr2[i]) return false;
    }
    return true;
}

// Test cases
console.log(checkInclusion("ab", "eidbaooo"));  // Output: true
console.log(checkInclusion("ab", "eidboaoo"));  // Output: false
console.log(checkInclusion("abc", "ccccbabaa"));  // Output: true
