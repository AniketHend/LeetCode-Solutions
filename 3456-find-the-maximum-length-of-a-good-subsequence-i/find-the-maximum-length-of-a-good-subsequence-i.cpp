// dp state
// dp[i][j][cnt] denotes the maximum possible length of good subsequence from 0
// to i th index such that ith index is considered into subsequce(1) or not(0)
// such tht cnt is nos of indices satisfying conidtion

// transition equations
// dp[i][1][cnt] = 1+ dp[j][1][cnt] if v[i]==v[j], including prev one and curr
//  else dp[i][1][cnt] = 1 + dp[j][0][cnt], including curr one
//  if(cnt<=k)dp[i][1][cnt] = 1+ dp[i-1][1][cnt-1];// including both

// dp[i][0][cnt] = max(dp[j][0][cnt],dp[j][1][cnt]);

// base case
// dp[0][0][0] = 0;
// dp[0][1][0] = 1;

// answer
// max(dp[n-1][1/0][cnt])

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
        for (int cnt = 0; cnt <= k; cnt++)
            dp[0][1][cnt] = 1;
        map<int, int> prev;
        prev[nums[0]] = 0;
        int mx = 1;
        for (int i = 1; i < n; i++) {

            for (int cnt = 0; cnt <= k; cnt++) {
                // exclude current one
                dp[i][0][cnt] =
                    max({dp[i - 1][0][cnt], dp[i][0][cnt], dp[i - 1][1][cnt]});
                dp[i][1][cnt] = 1;
                if (prev.find(nums[i]) != prev.end()) {
                    dp[i][1][cnt] =
                        max(dp[i][1][cnt], 1 + dp[prev[nums[i]]][1][cnt]);
                }
                if (cnt > 0)
                    dp[i][1][cnt] =
                        max(dp[i][1][cnt], 1 + dp[i - 1][0][cnt - 1]);
                if (nums[i] != nums[i - 1] && cnt > 0)
                    dp[i][1][cnt] =
                        max(dp[i][1][cnt], 1 + dp[i - 1][1][cnt - 1]);
                mx = max(mx, dp[i][1][cnt]);
            }
            prev[nums[i]] = i;
        }
        int ans = 0;
        for (int inc = 0; inc < 2; inc++) {
            for (int cnt = 0; cnt <= k; cnt++) {
                ans = max(ans, dp[n - 1][inc][cnt]);
            }
        }
        return mx;
    }
};