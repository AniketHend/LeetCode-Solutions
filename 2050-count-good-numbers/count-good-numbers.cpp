class Solution {
    long long mod = 1e9 + 7;

public:
    long long binexp(int a, long long b) {

        if (b == 0)
            return 1;
        if (b == 1)
            return a;
        long long temp = binexp(a, b / 2);
        temp *= temp;
        temp %= mod;
        if (b & 1) {
            temp *= a;
            temp %= mod;
        }
        return temp;
    }

    int countGoodNumbers(long long n) {
        if (n & 1) {
            return (binexp(4LL, (n / 2)) % mod * binexp(5LL, (n - n / 2)) %mod) %mod;
        } else {
            return (binexp(4LL, n / 2) % mod * binexp(5LL, (n / 2)) % mod) %mod;
        }
    }
};