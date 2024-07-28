class Solution {
public:
    Solution() {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        if (!erasePath(grid, 0, 0))
            return true;
        grid[0][0] = 1;
        return !erasePath(grid, 0, 0);
    }

    bool erasePath(vector<vector<int>>& grid, int row, int col) {
        if (row == grid.size() || col == grid[0].size() || grid[row][col] == 0)
            return false;

        if (row == grid.size() - 1 && col == grid[0].size() - 1)
            return true;

        grid[row][col] = 0;
        return erasePath(grid, row + 1, col) || erasePath(grid, row, col + 1);
    }
};