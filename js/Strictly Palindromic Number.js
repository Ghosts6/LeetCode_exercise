var isStrictlyPalindromic = function(n) {
    if (n <= 2) return true;
    for (let base = 2; base < n - 1; ++base) {
        if (!isPalindromic(n, base)) return false;
    }
    return true;
};
var isPalindromic = function(n, base) {
    const numInBase = convertToBase(n, base);
    let left = 0, right = numInBase.length - 1;
    while (left < right) {
        if (numInBase[left++] !== numInBase[right--]) return false;
    }
    return true;
};
var convertToBase = function(n, base) {
    let result = "";
    while (n > 0) {
        result = String(n % base) + result;
        n = Math.floor(n / base);
    }
    return result;
};