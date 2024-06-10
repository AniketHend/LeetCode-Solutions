#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using omset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

static const int _ = []() {ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0;}();

#define ff            first
#define ss            second
#define pb            push_back
#define ppb           pop_back
#define eb            emplace_back
#define vi            vector<int>
#define vl            vector<long long>
#define vii           vector<vector<int>>
#define vll           vector<vector<long long>>
#define pii           pair<int ,int>
#define pll           pair<long long, long long>
#define sz(x)         (int)(x.size())
#define all(x)        (x).begin(), (x).end()
#define allr(x)       (x).rbegin(), (x).rend()
#define up(a)         transform(all(a), a.begin(), ::toupper)
#define low(a)        transform(all(a), a.begin(), ::tolower)
#define sum(nums,x)   accumulate(nums.begin(), nums.end(), x)
#define tobin(n)      bitset<64>(n).to_string().substr(64 - (int)(log2(n)) - 1)
#define LSB(n)        (63-__builtin_clzll(n)) /* leftmost set bit */
#define RSB(n)        __builtin_ctzll(n)/* rightmost set bit */
#define BTS(n)        __builtin_popcount(n)

typedef long long ll;
typedef long double ld;

template<class T> using pqmin = priority_queue<T, vector<T>, greater<T>>;
template<class T> using pqmax = priority_queue<T>;
template<class T> void print(vector<T> &a) { for (auto &x : a) { cout << x << " "; } cout << endl; }

const int mod = 1000000007; // 1000000007 998244353
const ll lnf = 1e18;
const int inf = INT_MAX;

int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
void my_erase(omset<ll> &t, int v) { t.erase(t.find_by_order(t.order_of_key(v))); }
void my_erase(oset<ll> &t, int v) { t.erase(t.find_by_order(t.order_of_key(v))); }

struct Compress {
    vl a;
    int cnt;
    Compress() : cnt(0) {}
    void add(ll x) {a.push_back(x);}
    void init() {
        sort(all(a));
        a.erase(unique(all(a)), a.end());
        cnt = sz(a);
    }
    ll to(ll x) {
        int index = lower_bound(all(a), x) - a.begin();
        return index;
    }
    ll from(int x) {return a[x];}
    int size() {return cnt;}
};


#ifdef ONLINE_JUDGE
#include "debug.h"
#define dbg(...) cerr << __LINE__ << " :: ", debug::printer(#__VA_ARGS__, __VA_ARGS__)
#define dbgA(arr, n) cerr << __LINE__ << " :: ", debug::printerArr(#arr, arr, n)
#else
#define dbg(x...)
#define dbgA(arr, n)
#endif

/*
    #define int long long
    #undef int
*/

// solution
class Solution {
public:
    long long maxPower(vector<int>& a, int r, int k) {
        ll n = sz(a);

        auto chk = [&](ll m) {
            vl dp(n + 1);
            for (ll i = 0; i < n; i++) {
                ll x = max(0ll, i - r);
                ll y = min(n - 1, i + r);
                dp[x] += a[i];
                dp[y + 1] -= a[i];
            }

            ll sum = 0;
            ll op = k;
            for (ll i = 0; i < n; i++) {
                sum += dp[i];
                if (sum < m) {
                    ll d = m - sum;
                    if (d > op) return false;
                    op -= d;
                    sum += d;
                    if (i + 2 * r + 1 < n)dp[i + 2 * r + 1] -= d;
                }
            }
            return true;
        };
        ll ok = 0, ng = 1e18, ans = 0;
        while (ok <= ng) {
            ll m = (ok + ng) / 2;
            if (chk(m)) ans = m, ok = m + 1;
            else ng = m - 1;
        }
        return ans;
    }
};

void solve() {
    vi a = {1, 2, 4, 5, 0};
    dbg(Solution().maxPower(a, 1, 2));
}
#ifdef LOCAL
int32_t main() { solve(); }
#endif


