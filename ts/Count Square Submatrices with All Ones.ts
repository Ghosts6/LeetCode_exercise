function countSquares(matrix: number[][]): number {
    const m = matrix.length;
    const n = matrix[0].length;
    let count = 0;

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (matrix[i][j] === 1 && i > 0 && j > 0) {
                matrix[i][j] = Math.min(
                    matrix[i - 1][j],
                    matrix[i][j - 1],
                    matrix[i - 1][j - 1]
                ) + 1;
            }
            count += matrix[i][j];
        }
    }

    return count;
}
 
// test cases

