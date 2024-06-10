class Solution {
public:
    int maxTotalReward(vector<int>& A) {
        sort(A.begin(), A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
        int n = A.size();
        int sum = 0;

        map<int, int> dp, ndp;
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            ndp = dp;
            for (auto& [x, y] : dp) {
                if (x < A[i]) {
                    ndp[A[i] + x]++;
                    sum = max(sum, A[i] + x);
                } else
                    break;
            }
            dp = ndp;
        }
        return sum;
    }
};