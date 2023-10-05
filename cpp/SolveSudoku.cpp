class Solution {
public:
    bool isValid(int &num, int &i, int &j, int grid[N][N]) {
        for (int ii = 0; ii < 9; ii++) {
            if (grid[ii][j] == num) {
                return false;
            }
            if (grid[i][ii] == num) {
                return false;
            }
            if (grid[3 * (i / 3) + ii / 3][3 * (j / 3) + ii % 3] == num) {
                return false;
            }
        }
        return true;
    }

    bool SolveSudoku(int grid[N][N]) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 0) {
                    for (int num = 1; num <= 9; ++num) {
                        if (isValid(num, i, j, grid)) {
                            grid[i][j] = num;
                            if (SolveSudoku(grid)) {
                                return true;
                            }
                            grid[i][j] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void printGrid(int grid[N][N]) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) 
                cout << grid[i][j] << " ";
        }
    }
};
