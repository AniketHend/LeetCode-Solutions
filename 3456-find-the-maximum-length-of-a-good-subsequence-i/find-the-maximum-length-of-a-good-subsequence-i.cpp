class Solution {
public:
    int maximumLength(vector<int>& nums, int op) {
        // map<tuple<int,int,int>, int> dp;
        int n = nums.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(op+1,-1)));
        function<int(int, int, int)> fn = [&](int i, int j, int k) {
            if (i == n) return 0;
            if (dp[i][j+1][k]!=-1) return dp[i][j+1][k];
            int ans = 0;
            if (j == -1){
                ans = max(ans, max(1 + fn(i+1, i, k), fn(i+1, j, k)));
            }
            if (k >= 0 && j != -1){
                if (nums[i] == nums[j]) {
                    ans = max(ans, 1+fn(i+1, i, k));
                } else {
                    ans = max(ans, fn(i+1, j, k));
                }
            }
            if (k > 0 && j != -1){
                ans = max(ans, 1+fn(i+1,i,k-1));
            }
            return dp[i][j+1][k] = ans;
        };
        return fn(0, -1, op);
    }
};