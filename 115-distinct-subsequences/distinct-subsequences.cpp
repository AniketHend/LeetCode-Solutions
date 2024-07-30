int dp[1001][1001];
class Solution {
    int f(int i, int j, const string& s, const string& t) {
        if (j >= t.size()) return 1;
        if (i >= s.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = f(i + 1, j, s, t) + (s[i] == t[j] ? f(i + 1, j + 1, s, t) : 0);
    }
public:
    int numDistinct(string s, string t) {
        memset(dp, -1, sizeof dp);
        return f(0, 0, s, t);
    }
};