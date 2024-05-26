var getMaximumGold = function(grid) {
    const m = grid.length;
    const n = grid[0].length;

    function backtrack(i, j) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] === 0) {
            return 0;
        }

        const gold = grid[i][j];
        grid[i][j] = 0;
        let maxGold = 0;
        const directions = [[0, 1], [0, -1], [1, 0], [-1, 0]];
        for (const [dx, dy] of directions) {
            maxGold = Math.max(maxGold, gold + backtrack(i + dx, j + dy));
        }
        grid[i][j] = gold;

        return maxGold;
    }

    let maxGold = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (grid[i][j] !== 0) {
                maxGold = Math.max(maxGold, backtrack(i, j));
            }
        }
    }
    return maxGold;
};