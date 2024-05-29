static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int mp,n,m;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};
    void dfs(int i, int j, vector<vector<int>>& grid, int profit) {
        int x = grid[i][j];
        profit += x;
        grid[i][j] = 0;
        mp = max(profit,  mp);
        for (const auto &dir : directions) {
            int neighbour_i = i + dir[0];
            int neighbour_j = j + dir[1];
            if (neighbour_i < 0 || neighbour_j < 0 || neighbour_i >= n || neighbour_j >= m)
                continue;
            if (grid[neighbour_i][neighbour_j] == 0)
                continue;
            dfs(neighbour_i, neighbour_j, grid, profit);
        }
        grid[i][j] = x;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        mp = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) {
                    int profit = 0;
                    dfs(i, j, grid, profit);
                }
            }
        }
        return mp;
    }
};