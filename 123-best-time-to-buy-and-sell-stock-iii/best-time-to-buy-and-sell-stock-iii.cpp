class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(int i , int t , int flg , vector<int> &nums){
        if (i == nums.size() || t == 0) return 0 ;
        if (dp[i][t][flg] != -1)return dp[i][t][flg] ;
        int buy = 0 , sell = 0 , next = 0 ;
        if (flg)
            buy = -nums[i] + solve(i+1 , t , 0 , nums) ;
        else 
            sell = +nums[i] + solve(i+1 , t-1, 1, nums);
        next = solve(i+1 , t , flg , nums) ;
        return dp[i][t][flg] = max(max(buy,next),max(sell,next));
    }
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size() , vector<vector<int>> (3 , vector<int> (2 , -1 ))); 
        return solve(0 , 2 , 1 , prices) ;
    }
};
