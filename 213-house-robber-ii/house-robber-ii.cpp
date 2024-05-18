int dp[102][2];
class Solution {
    int f(int i, int t, vector<int>& nums) {
        if (i >= nums.size())
            return 0;
        if (dp[i][t] != -1)
            return dp[i][t];
        int p = 0, q = 0;
        if (i == nums.size() - 1 && t == 0)
            p = nums[i] + f(i + 2, t, nums);
        else if (i != nums.size() - 1) {
            p = nums[i] + f(i + 2, t | (i == 0), nums);
        }
        q = f(i + 1, t, nums);
        return dp[i][t] = max(p, q);
    }

public:
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        return f(0, 0, nums);
    }
};