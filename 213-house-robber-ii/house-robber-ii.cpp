class Solution {
public:
    int func(int indx, vector<int>& valueInHouse, vector<int>& dp) {
        // if (indx == 0) {
        //     return valueInHouse[indx];
        // }
        if (indx < 0) {
            return 0;
        }
        if (dp[indx] != -1) {
            return dp[indx];
        }
        int pick = valueInHouse[indx] + func(indx - 2, valueInHouse, dp);
        int notPick = 0 + func(indx - 1, valueInHouse, dp);
        return dp[indx] = max(pick, notPick);
    }
    int rob(vector<int>& valueInHouse) {

        int n = valueInHouse.size();
        if(n==1) return valueInHouse[0];
        vector<int> dp(n, -1);
        vector<int> temp1, temp2;
        for (int i = 0; i < n; i++) {
            if (i != 0) {
                temp1.push_back(valueInHouse[i]);
            }
            if (i != n - 1) {
                temp2.push_back(valueInHouse[i]);
            }
        }

        int x = func(temp1.size() - 1, temp1, dp);
        dp.assign(n, -1);
        int y = func(temp2.size() - 1, temp2, dp);
        // cout << temp2[0] << endl;
        return max(x, y);
    }
};