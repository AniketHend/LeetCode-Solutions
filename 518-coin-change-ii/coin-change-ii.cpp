class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0) {
                dp[0][i] = 1;
            } else {
                dp[0][i] = 0;
            }
        }
        for (int ind = 1; ind < n; ind++) {
            for (int t = 0; t <= amount; t++) {
                int notTaken = dp[ind - 1][t];
                int taken = 0;
                if (coins[ind] <= t) {
                    taken = dp[ind][t - coins[ind]];
                }
                dp[ind][t] = taken + notTaken;
            }
        }
        return dp[n - 1][amount];
    }
};