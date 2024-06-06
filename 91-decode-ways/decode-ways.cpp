// Code : 1 
class Solution {
public:
    int dp[1000];
    int solve(int idx, int n, string s) {
        if (idx >= n)
            return 1;
        if (dp[idx] != -1)
            return dp[idx];
        int ans = 0;
        string x = "";
        for (int i = idx; i < idx + 2 && i < n; i++) {
            x.push_back(s[i]);
            if (stoi(x) != 0 && stoi(x) <= 26)
                ans += solve(i + 1, n, s);
            else
                return ans;
        }
        return dp[idx] = ans;
    }

    int numDecodings(string s) {
        memset(dp, -1, sizeof dp);
        return solve(0, s.size(), s);
    }
};
// Code : 2
// class Solution {
// public:
//     int dp[1000];
//     int solve(int idx, int n, string s) {
//         if (idx >= n)
//             return 1;
//         if (dp[idx] != -1)
//             return dp[idx];
//         int ans = 0;
//         string x = "";
//         for (int i = idx; i < idx + 3 && i < n; i++) {
//             x.push_back(s[i]);
//             if (stoi(x) != 0 && stoi(x) <= 26)
//                 ans += solve(i + 1, n, s);
//             else
//                 return dp[idx] = ans;
//         }
//         return dp[idx] = ans;
//     }

//     int numDecodings(string s) {
//         memset(dp, -1, sizeof dp);
//         return solve(0, s.size(), s);
//     }
// };