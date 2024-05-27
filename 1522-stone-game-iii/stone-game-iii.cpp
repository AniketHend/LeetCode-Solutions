class Solution {
public:
    int meth(vector<int> &a,int curr,vector<int> &dp)
    {
        if(curr>=a.size())
        {
            return 0;
        }
        if(dp[curr]!=-1)
        {
            return dp[curr];
        }
        int result=INT_MIN;
        int total=0;
        for(int i=0;i<3;i++)
        {
            if(curr+i<a.size())
            {
                total+=a[i+curr];
                int x=total-meth(a,curr+i+1,dp);
                result=max(result,x);
            }
        }
        return dp[curr]=result;
    }
    string stoneGameIII(vector<int>& a) {
        int n=a.size();
        vector<int> dp(n,-1);
        int r=meth(a,0,dp);
        if(r>0)
        return "Alice";
        else if(r==0)
        return "Tie";
        else
        return "Bob";
    }
};
