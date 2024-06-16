class Solution {
    public int paintWalls(int[] cost, int[] time) {
        return (int) check(cost, time);
    }

    public long check(int cost[], int time[]) {

        int n = cost.length;
        long dp[][] = new long[n + 1][500 + 1]; // minimum cost such that total atleast j walls are painted
        // dp[i][j] = Math.min(dp[i-1][j],dp[i-1][j-time[i]]+cost[i])
        for (int i = 0; i <= n; i++) {
            Arrays.fill(dp[i], Integer.MAX_VALUE);
        }
        dp[0][0] = 0;
        // for (int i = 0; i <= n; i++) {
        //     dp[i][0] = 0;
        // }
        // System.out.println(n);

        long ans = Integer.MAX_VALUE;
        long y = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 500; j++) {
                dp[i][j] = Math.min(dp[i - 1][j], dp[i][j]);
                dp[i][j] = Math.min(dp[i][j], dp[i - 1][Math.max(0, j - time[i - 1] - 1)] + cost[i - 1]);
                if (i == n && j >= n)
                    ans = Math.min(ans, dp[i][j]);
            }
            y += cost[i - 1];
        }
        return ans;
    }
}