class Solution {
public:
    // recursion+memoization
    int f(vector<int>&prices,int ind,int flag,int canhave,vector<vector<vector<int>>>&dp)
    {
        if(ind==prices.size() or canhave==0)
            return 0;
        if(dp[ind][flag][canhave]!=-1)
            return dp[ind][flag][canhave];
        int buy=0,notbuy=0,sell=0,notsell=0;
        // we can buy it 
        if(flag==1)
        {
            // buy or not buy
            buy=-prices[ind]+f(prices,ind+1,1-flag,canhave,dp);
        }//we can sell it
        else
        {
            //sell or not sell
            sell=prices[ind]+f(prices,ind+1,1-flag,canhave-1,dp);
        }
            notsell=f(prices,ind+1,flag,canhave,dp);
        return dp[ind][flag][canhave] =max(max(buy,notbuy),max(sell,notsell));
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(prices,0,1,2,dp);
        /*
        tabulation
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=1;j++)
            {
                for(int k=0;k<=2;k++)
                {
                    if(k==0)
                    {
                        dp[i][j][k]=0;
                    }
                    else
                    {
                        int buy=0,notbuy=0,sell=0,notsell=0;
                        // we can buy it 
                        if(j==1)
                        {
                            // buy or not buy
                            buy=-prices[i]+dp[i+1][1^j][k];
                            notbuy=dp[i+1][j][k];
                        }//we can sell it
                        else
                        {
                            //sell or not sell
                            sell=prices[i]+dp[i+1][1^j][k-1];
                            notsell=dp[i+1][j][k];
                        }
                        dp[i][j][k]=max(max(buy,notbuy),max(sell,notsell));
                    }
                }
            }
        }
        return dp[0][1][2];
        
        // space optimization
        vector<vector<int>>next(2,vector<int>(3,0)),curr(2,vector<int>(3,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=1;j++)
            {
                for(int k=1;k<=2;k++)
                {
                    int buy=0,notbuy=0,sell=0,notsell=0;
                    // we can buy it 
                    if(j==1)
                    {
                        // buy or not buy
                        buy=-prices[i]+next[1^j][k];
                        notbuy=next[j][k];
                    }//we can sell it
                    else
                    {
                        //sell or not sell
                        sell=prices[i]+next[1^j][k-1];
                        notsell=next[j][k];
                    }
                    curr[j][k]=max(max(buy,notbuy),max(sell,notsell));
                }
                next=curr;
            }
        }
        return curr[1][2];*/
    }
};