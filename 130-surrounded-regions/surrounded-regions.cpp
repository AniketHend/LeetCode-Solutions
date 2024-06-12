class Solution {
public:
    void dfs(int a, int b, vector<vector<int>>& vis,
             vector<vector<char>>& board, vector<int>& delrow,
             vector<int>& delcol) {
        vis[a][b] = 1;
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < 4; i++) {
            int nrow = a + delrow[i];
            int ncol = b + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                vis[nrow][ncol] == 0 && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, vis, board, delrow, delcol);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol = {0, 1, 0, -1};

        for (int i = 0; i < m; i++) {
            if (!vis[0][i] && board[0][i] == 'O') {
                dfs(0, i, vis, board, delrow, delcol);
            }
            if (!vis[n - 1][i] && board[n - 1][i] == 'O') {
                dfs(n - 1, i, vis, board, delrow, delcol);
            }
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && board[i][0] == 'O') {
                dfs(i, 0, vis, board, delrow, delcol);
            }
            if (!vis[i][m - 1] && board[i][m - 1] == 'O') {
                dfs(i, m - 1, vis, board, delrow, delcol);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};