const int MOD = 1e9 + 7;
long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }

class Solution {
public:
    bool isPossible(long long mid, long long n, int a, int b) {
        long long x = mid / a;
        long long y = mid / b;
        long long z = mid / lcm(a, b);
        return x + y - z >= n;
    }

    int nthMagicalNumber(int n, int a, int b) {
        long long low = min(a, b);
        long long high = 1e18;

        long long ans = -1;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (isPossible(mid, n, a, b)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans % MOD;
    }
};
