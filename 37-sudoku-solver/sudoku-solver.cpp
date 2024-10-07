class Solution {
public:
    char a[9][9];
    int filly = 0;
    vector<pair<int, int>> v;
    vector<vector<char>> praga;
    bool val(int row, int col, int num) {
        int c = 0;
        int startrow, startcol;
        startrow = row - (row % 3);
        startcol = col - (col % 3);
        for (int i = startrow; i < startrow + 3; i++) {
            for (int j = startcol; j < startcol + 3; j++) {
                int fix;
                fix = a[i][j] - '0';
                if (fix == num) {
                    c++;
                }
            }
        }
        for (int i = 0; i < row; i++) {
            int fix;
            fix = a[i][col] - '0';
            if (fix == num) {
                c++;
            }
        }
        for (int i = row; i < 9; i++) {
            int fix;
            fix = a[i][col] - '0';
            if (fix == num) {
                c++;
            }
        }
        for (int i = 0; i < col; i++) {
            int fix;
            fix = a[row][i] - '0';
            if (fix == num) {
                c++;
            }
        }
        for (int i = col; i < 9; i++) {
            int fix;
            fix = a[row][i] - '0';
            if (fix == num) {
                c++;
            }
        }
        if (c == 0) {
            return true;
        } else {
            return false;
        }
    }

    int ok = 0;
    char ans[9][9];
    void rec(int ind, int count) {
        if (ok == 1) {
            return;
        }
        if (ind == v.size()) {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    ans[i][j] = a[i][j];
                }
            }
            ok++;
            return;
        }
        int row, col;
        row = v[ind].first;
        col = v[ind].second;
        for (int i = 1; i <= 9; i++) {
            if (val(row, col, i) == true) {
                string rf;
                rf = to_string(i);
                char gp;
                gp = rf[0];
                a[row][col] = gp;
                ind = ind + 1;
                count = count + 1;
                rec(ind, count); // index of pair ,
                count = count - 1;
                ind = ind - 1;
                a[row][col] = '.';
            }
            if (i == 9) {
                return;
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                // cin>>a[i][j];
                a[i][j] = board[i][j];
                if (a[i][j] == '.') {
                    v.push_back(make_pair(i, j));
                    filly++;
                }
            }
        }
        int row, col;
        int got = 0;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (a[i][j] == '.') {
                    row = i;
                    col = j;
                    got++;
                    break;
                }
            }
            if (got == 1) {
                break;
            }
        }
        int count = 0;
        for (int i = 1; i <= 9; i++) {
            if (ok == 1) {
                break;
            }
            if (val(row, col, i) == true) {
                string rf;
                rf = to_string(i);
                char gp;
                gp = rf[0];
                a[row][col] = gp;
                count = count + 1;
                rec(1, count); // index of pair ,
                count = count - 1;
                a[row][col] = '.';
            }
        }

        for (int i = 0; i < 9; i++) {
            vector<char> dpp;
            for (int j = 0; j < 9; j++) {
                dpp.push_back(ans[i][j]);
            }
            praga.push_back(dpp);
        }
        
        board = praga;
    }
};