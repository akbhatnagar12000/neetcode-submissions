class Solution {
    vector<string> temp;
    vector<vector<string>> res;

public:
    bool isSafe(int r, int c, int n) {

        for (int j = c - 1; j >= 0; j--)
            if (temp[r][j] == 'Q')
                return false;

        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--)
            if (temp[i][j] == 'Q')
                return false;

        for (int i = r + 1, j = c - 1; i < n && j >= 0; i++, j--)
            if (temp[i][j] == 'Q')
                return false;

        return true;
    }

    void solveRec(int col, int n) {
        if (col == n) {
            res.push_back(temp);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, n)) {
                temp[row][col] = 'Q';
                solveRec(col + 1, n);
                temp[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        temp = vector<string>(n, string(n, '.'));
        solveRec(0, n);
        return res;
    }
};