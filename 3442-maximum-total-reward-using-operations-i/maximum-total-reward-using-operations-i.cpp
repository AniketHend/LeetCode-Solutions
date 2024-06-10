class Solution {
public:
    int maxTotalReward(vector<int>& rewards) {
        if (rewards.size() == 1)
            return rewards[0];
        int n = rewards.size();
        vector<int> dp(4002 + 1, 0), ndp(4002, 0);
        sort(rewards.begin(), rewards.end());

        for (int r = 0; r < 4002; r++) {
            if (rewards[n - 1] > r)
                dp[r] = rewards[n - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int rm = 0; rm < 4002; rm++) {
                if (rewards[i] > rm) {
                    if (rm + rewards[i] > 4002)
                        ndp[rm] = max(dp[rm], rewards[i]);
                    ndp[rm] = max(dp[rm], rewards[i] + dp[rm + rewards[i]]);
                } else
                    ndp[rm] = dp[rm];
            }
            dp = ndp;
        }

        return dp[0];
    }
};