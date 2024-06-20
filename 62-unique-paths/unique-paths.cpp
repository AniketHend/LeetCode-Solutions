class Solution {
public:
    long long mminvprime(long long x, long long p) {
        long long y = p - 2;
        long long res = 1;
        x = x % p;

        while (y > 0) {
            if (y & 1)
                res = (res * x) % p;
            y = y >> 1;
            x = (x * x) % p;
        }
        return res;
    }

    long long mod_mul(long long x, long long y, long long MOD) {
        long long ans = x % MOD;
        ans = (ans * (y % MOD)) % MOD;

        return ans;
    }

    int uniquePaths(int m, int n) {
        int maxn = 201;

        vector<long long> fact(maxn + 1);
        vector<long long> ifact(maxn + 1);

        fact[0] = 1;
        int MOD = INT_MAX;
        for (int i = 1; i <= maxn; i++) {
            fact[i] = mod_mul(fact[i - 1], i, MOD);
        }

        ifact[maxn] = mminvprime(fact[maxn], MOD);

        for (int i = maxn - 1; i >= 0; i--) {
            ifact[i] = mod_mul(ifact[i + 1], i + 1, MOD);
        };

        return mod_mul(fact[n + m - 2],
                       mod_mul(ifact[n - 1], ifact[m - 1], MOD), MOD);
    }
};
