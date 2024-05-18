class Solution {
private:
    long long gcd(long long a, long long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }

    long long checker(long long mid, int a, int b) {
        long long count = 0;
        count += mid / a;
        count += mid / b;
        count -= mid / (lcm(a, b));
        return count;
    }

public:
    int nthMagicalNumber(int n, int a, int b) {
        long long low = 1;
        long long high = 1e18;
        long long ans;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (checker(mid, a, b) >= n) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans % ((long long)1e9 + 7);
    }
};