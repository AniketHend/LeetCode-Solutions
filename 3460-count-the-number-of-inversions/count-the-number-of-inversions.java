class Solution {
    int mod = 1000000007;

    int func(int i, int sum, int N, int cond[], int dp[][]) {
        if (i == N) {
            System.out.println(sum);
            return 1;
        }
        if (sum > 400)
            return 0;
        if (dp[i][sum] != -1) {
            return dp[i][sum];
        }
        int ans = 0;
        for (int index = sum; index <= sum + i; index++) {
            if (cond[i] != -1 && cond[i] != index)
                continue;
            ans = (ans + func(i + 1, index, N, cond, dp)) % mod;
        }
        return dp[i][sum] = ans;
    }

    public int numberOfPermutations(int n, int[][] requirements) {
        int cond[] = new int[n];
        Arrays.fill(cond, -1);
        for (int a[] : requirements) {
            cond[a[0]] = a[1];
        }
        int dp[][] = new int[n][402];
        for (int i = 0; i < n; i++)
            Arrays.fill(dp[i], -1);
        return func(0, 0, n, cond, dp);
    }
}