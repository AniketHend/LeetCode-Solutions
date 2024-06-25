class Solution {
    public int countPartitions(int[] nums, int k) {
        long sum = 0;
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if(sum < (long)2*k || n<=1)
            return 0;
        long dp[][] = new long[n + 1][k];
        dp[0][0] = 1;
        int mod = (int) 1e9 + 7;
        long ans = 1;
        for (int i = 1; i <= n; i++) {
            ans *= 2;
            ans %= mod;
            for (int j = 0; j < k; j++) {
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= mod;
                if (j >= nums[i - 1])
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
                dp[i][j] %= mod;
            }
        }
        long remove = 0;
        for (int i = 0; i < k; i++) {
            remove += dp[n][i];
            remove %= mod;
        }
        remove *= 2;
        remove %= mod;
        ans -= remove;
        if (ans < 0)
            ans += mod;
        return (int) ans;
    }
}