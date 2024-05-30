class Solution {

public:
    long long MOD = INT_MAX;
    long long mod(long long x) { return ((x % MOD + MOD) % MOD); }
    long long add(long long a, long long b) { return mod(mod(a) + mod(b)); }
    long long sub(long long a, long long b) {
        return mod(mod(a) - mod(b) + MOD);
    }

    long long mul(long long a, long long b) { return mod(mod(a) * mod(b)); }

    long long binpow(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    int uniquePaths(int m, int n) {

        int sum = n + m - 2;

        // factorial calculator

        long long n1 = sum;
        vector<long long> fact(n1 + 1);
        vector<long long> ifact(n1 + 1);

        fact[0] = 1;

        for (long long i = 1; i < n1 + 1; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }

        ifact[n1] = binpow(fact[n1], MOD - 2);
        for (long long i = n1 - 1; i >= 0; i--) {
            ifact[i] = mul(ifact[i + 1], (i + 1));
        }

        // calc the result //D D D D D  RR  R R R ke different arrangements

        int ans = mul(fact[sum], mul(ifact[n - 1], ifact[m - 1]));
        return ans;
    }
};