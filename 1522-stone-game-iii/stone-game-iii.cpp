class Solution {
public:
    int meth(int i, vector<int>& a, vector<int>& dp) {
        if (i >= a.size())
            return 0;
        if (dp[i] != -1) {
            return dp[i];
        }
        int choice1 = a[i] - meth(i + 1, a, dp);
        int choice2 = INT_MIN, choice3 = INT_MIN;
        if (i + 1 < a.size())
            choice2 = a[i] + a[i + 1] - meth(i + 2, a, dp);
        if (i + 2 < a.size())
            choice3 = a[i] + a[i + 1] + a[i + 2] - meth(i + 3, a, dp);
        return dp[i] = max(choice1,max(choice2,choice3));
    }
    string stoneGameIII(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n, -1);
        int x = meth(0, a, dp);
        if (x > 0)
            return "Alice";
        else if (x < 0)
            return "Bob";
        else
            return "Tie";
    }
};