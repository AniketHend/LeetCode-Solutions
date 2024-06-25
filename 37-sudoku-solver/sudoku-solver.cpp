static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
    bool safe(int i, int j, vector<vector<char>>& board, char ch) {
        for (int k = i; k >= 0; k--) {
            if (board[k][j] == ch)
                return false;
        }
        for (int k = i; k < 9; k++)
            if (board[k][j] == ch)
                return false;
        for (int k = j; k >= 0; k--) {
            if (board[i][k] == ch)
                return false;
        }
        for (int k = j; k < 9; k++) {
            if (board[i][k] == ch)
                return false;
        }
        int x = (i / 3) * 3;
        int y = (j / 3) * 3;
        for (int p = x; p < x + 3; p++) {
            for (int q = y; q < y + 3; q++) {
                if (board[p][q] == ch)
                    return false;
            }
        }
        return true;
    }
    bool f(int i, int j, vector<vector<char>>& board) {
        if (i == 9) {
            return true;
        }
        if (j == 9) {
            return f(i + 1, 0, board);
        }
        if (board[i][j] != '.') {
            return f(i, j + 1, board);
        }
        for (char ch = '1'; ch <= '9'; ch++) {
            if (safe(i, j, board, ch)) {
                board[i][j] = ch;
                bool ok = f(i, j + 1, board);
                if (ok) {
                    return true;
                }
                board[i][j] = '.';
            }
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        f(0, 0, board);
    }
};