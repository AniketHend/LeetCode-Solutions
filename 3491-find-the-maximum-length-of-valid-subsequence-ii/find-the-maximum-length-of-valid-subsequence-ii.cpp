class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            vector<int> dp(k);
            for (int j = 0; j < nums.size(); j++) {
                int c = nums[j] % k;
                int r = (i - c + k) % k;
                dp[c] = max(dp[c], dp[r] + 1);
                ans = max(ans, dp[c]);
            }
        }
        return ans;
    }
};