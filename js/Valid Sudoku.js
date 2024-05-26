var isValidSudoku = function(board) {
    var rows = new Array(9).fill().map(() => new Set());
    var cols = new Array(9).fill().map(() => new Set());
    var boxes = new Array(9).fill().map(() => new Set());

    for (var i = 0; i < 9; ++i) {
        for (var j = 0; j < 9; ++j) {
            var current = board[i][j];
            if (current === '.') continue;
            if (rows[i].has(current) || cols[j].has(current) || boxes[Math.floor(i / 3) * 3 + Math.floor(j / 3)].has(current))
                return false;
            rows[i].add(current);
            cols[j].add(current);
            boxes[Math.floor(i / 3) * 3 + Math.floor(j / 3)].add(current);
        }
    }

    return true;
};