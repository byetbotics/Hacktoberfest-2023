function solveNQueens(n) {
    const solutions = [];
    const board = Array.from({ length: n }, () => Array(n).fill('.'));

    const isSafe = (board, row, col) => {
        for (let i = 0; i < row; i++) {
            if (board[i][col] === 'Q') return false;
            
            // Check upper left diagonal
            if (col - (row - i) >= 0 && board[i][col - (row - i)] === 'Q') return false;
            
            // Check upper right diagonal
            if (col + (row - i) < n && board[i][col + (row - i)] === 'Q') return false;
        }
        return true;
    }

    const solve = (currentRow) => {
        if (currentRow === n) {
            solutions.push(board.map(row => row.join('')));
            return;
        }

        for (let i = 0; i < n; i++) {
            if (isSafe(board, currentRow, i)) {
                board[currentRow][i] = 'Q';
                solve(currentRow + 1);
                board[currentRow][i] = '.';
            }
        }
    }

    solve(0);
    return solutions;
}

// For example, to solve for a 4x4 board:
const solutions = solveNQueens(4);
console.log(solutions);
