class Solution {
public:
    int dp[201][20001];
    // bool rec(int i , int target , vector<int>& nums)
    // {
    //     if(target==0)
    //     {
    //         return true;
    //     }
    //     if(i==0)
    //     {
    //         return nums[i]==target;
    //     }
    //     if(dp[i][target]!=-1)
    //     {
    //         return dp[i][target];
    //     }
    //     bool ans=false;
    //     if(target>=nums[i])
    //     {
    //         ans = ans|rec(i-1,target-nums[i],nums);
    //     }
    //     ans |= rec(i-1,target,nums);
    //     return dp[i][target]=ans;
    // }
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        memset(dp, 0, sizeof(dp));
        if (sum % 2 != 0) {
            return false;
        }
        dp[n][0] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int target = sum / 2; target >= 1; target--) {
                if (target >= arr[i]) {
                    dp[i][target] |= dp[i + 1][target - arr[i]];
                }
                dp[i][target] |= dp[i + 1][target];
            }
        }
        return dp[0][sum / 2];
    }
};