var countPrefixSuffixPairs = function (words) {
    function isPrefixAndSuffix(str1, str2) {
        return str2.startsWith(str1) && str2.endsWith(str1);
    }

    let count = 0;

    for (let i = 0; i < words.length; i++) {
        for (let j = i + 1; j < words.length; j++) {
            if (isPrefixAndSuffix(words[i], words[j])) {
                count++;
            }
        }
    }

    return count;
}

// Test cases
console.log(countPrefixSuffixPairs(["a","aba","ababa","aa"])) // Expected Output: 4
console.log(countPrefixSuffixPairs(["pa","papa","ma","mama"])) // Expected Output: 2
console.log(countPrefixSuffixPairs(["abab","ab"])) // Expected Output: 0