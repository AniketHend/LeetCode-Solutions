// solution
class Solution {
public:
    int minimumDifference(vector<int>& A, int k) {
        int N = A.size();
        vector<vector<int>> bit(N + 1, vector<int>(30));
        for (int i = 0; i < N; ++i) {
            bit[i + 1] = bit[i];
            for (int bt = 29; bt >= 0; --bt)
                if (A[i] >> bt & 1)
                    bit[i + 1][bt] += 1;
        }

        auto get = [&](int l, int r) {
            int ans = 0;
            for (int i = 0; i < 30; ++i)
                if (bit[r][i] - bit[l][i] == r - l) {
                    ans ^= 1 << i;
                }
            return ans;
        };

        int l = 0;
        int ans = INT_MAX;
        for (int i = 0; i < N; ++i) {
            while (l < i && get(l, i + 1) < k) {
                ans = min(ans, abs(get(l, i + 1) - k));
                ++l;
            }
            ans = min(ans, abs(get(l, i + 1) - k));
        }
        return ans;
    }
};
