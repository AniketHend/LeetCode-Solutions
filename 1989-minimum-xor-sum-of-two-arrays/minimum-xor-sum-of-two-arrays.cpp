class Solution {
public:
    int fun(int i, vector<int>& a, vector<int>& b, int mask,
            vector<vector<int>>& dp) {
        if (i == a.size()) {
            return 0;
        }
        if (dp[i][mask] == INT_MAX) {
            for (int j = 0; j < a.size(); j++) {
                if ((mask & (1 << j)) == 0) {
                    dp[i][mask] = min(
                        dp[i][mask],
                        (a[i] ^ b[j]) + fun(i + 1, a, b, mask + (1 << j), dp));
                }
            }
        }

        return dp[i][mask];
    }

    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int mask = 0;
        vector<vector<int>> dp(14, vector<int>((1 << 14), INT_MAX));

        return fun(0, nums1, nums2, mask, dp);
    }
};