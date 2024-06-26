function closeStrings(word1, word2) {
    if (word1.length !== word2.length) {
        return false;
    }

    const count1 = {};
    const count2 = {};

    for (let c of word1) {
        count1[c] = (count1[c] || 0) + 1;
    }
    for (let c of word2) {
        count2[c] = (count2[c] || 0) + 1;
    }

    if (Object.keys(count1).length !== Object.keys(count2).length) {
        return false;
    }

    for (let key in count1) {
        if (!(key in count2)) {
            return false;
        }
    }

    const freq1 = Object.values(count1).sort((a, b) => a - b);
    const freq2 = Object.values(count2).sort((a, b) => a - b);

    return JSON.stringify(freq1) === JSON.stringify(freq2);
}


const word1 = "abc";
const word2 = "bca";
console.log(closeStrings(word1, word2)); 