class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        int n = a.size();
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                int x1 = j;
                int y1 = n - 1 - i;

                int x2 = n - 1 - i;
                int y2 = n - 1 - j;

                int x3 = n - 1 - j;
                int y3 = i;

                int p = a[x1][y1];
                a[x1][y1] = a[i][j];
                swap(p, a[x2][y2]);
                swap(p, a[x3][y3]);
                a[i][j] = p;
            }
        }
        if (n & 1) {
            for (int i = 0; i < n / 2; i++) {
                int j = n / 2;
                int x1 = j;
                int y1 = n - 1 - i;

                int x2 = n - 1 - i;
                int y2 = n - 1 - j;

                int x3 = n - 1 - j;
                int y3 = i;

                int p = a[x1][y1];
                a[x1][y1] = a[i][j];
                swap(p, a[x2][y2]);
                swap(p, a[x3][y3]);
                a[i][j] = p;
            }
        }
    }
};