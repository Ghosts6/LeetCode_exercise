var numJewelsInStones = function(jewels, stones) {
    const jewelSet = new Set(jewels);
    let jewelCount = 0;
    for (let i = 0; i < stones.length; i++) {
        if (jewelSet.has(stones[i])) {
            jewelCount++;
        }
    }
    return jewelCount;
};