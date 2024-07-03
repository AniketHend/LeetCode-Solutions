class Solution {
public:
    int dp[201][20001];
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        memset(dp, 0, sizeof(dp));
        if (sum % 2 != 0) {
            return false;
        }
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int target = sum / 2; target >= 1; target--) {
                if (target >= arr[i - 1]) {
                    dp[i][target] |= dp[i - 1][target - arr[i - 1]];
                }
                dp[i][target] |= dp[i - 1][target];
            }
        }
        return dp[n][sum / 2];
    }
};