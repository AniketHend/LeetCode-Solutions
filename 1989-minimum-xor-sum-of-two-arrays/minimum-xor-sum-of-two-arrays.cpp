#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define pb push_back
#define MOD 1000000007
#define inf 1e18

int solve(int i, int mask, vector<vector<int>>& dp, vector<int>& nums1,
          vector<int>& nums2) {
    if (i == nums1.size()) {
        return 0;
    }
    if (dp[i][mask] != -1) {
        return dp[i][mask];
    }
    int res = INT_MAX;
    for (int k = 0; k < nums1.size(); k++) {
        if ((mask & (1 << k)) == 0) { // jth element is not used till now
            res = min(res, ((nums1[i] ^ nums2[k]) + solve(i + 1, mask | (1 << k),
                                                        dp, nums1, nums2)));
        }
    }
    return dp[i][mask] = res;
}

class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        // since the given question hai n = 14 so i can apply the approach of dp
        // with bitmasking yrr

        int n = nums1.size();
        vector<vector<int>> dp(n + 1, vector<int>(1 << (n + 1), -1));
        return solve(0, 0, dp, nums1, nums2);
    }
};

#ifdef LOCAL
int32_t main() {
    freopen("output.txt", "w", stdout);
    cout << "Compiled!" << endl;
}
#endif
