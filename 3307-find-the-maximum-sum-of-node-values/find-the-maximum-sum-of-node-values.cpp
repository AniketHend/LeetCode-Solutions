#include <bits/stdc++.h>
using namespace std;

static const int _ = []() {ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0;}();

#ifdef ONLINE_JUDGE
#include "./debug.h"
#define dbg(...)                                                               \
    cerr << __LINE__ << " :: ", _DEBUG_UTIL_::printer(#__VA_ARGS__, __VA_ARGS__)
#define dbgA(arr, n)                                                           \
    cerr << __LINE__ << " :: ", _DEBUG_UTIL_::printerArr(#arr, arr, n)
#else
#define dbg(x...)
#define dbgA(arr, n)
#endif

#define ff first
#define ss second
#define All(x) (x).begin(), (x).end()
#define Allr(x) (x).rbegin(), (x).rend()
#define sz(x) static_cast<int>(x.size())
#define vi vector<long long>
#define pi pair<long long, long long>
typedef long long ll;
typedef long double ld;

const int mod = 1000000007; // 1000000007 998244353
const ll inf = 1e18;

template <typename Func> class FUN_res {Func func_; public: template <typename T>explicit FUN_res(T&& func) : func_(std::forward<T>(func)) {} template <typename... Args> decltype(auto) operator()(Args&&... args) {return func_(std::ref(*this), std::forward<Args>(args)...);}}; template <typename Func> decltype(auto) FUN(Func&& func) {return FUN_res<std::decay_t<Func>>(std::forward<Func>(func));}

class Solution {
public:
    long long maximumValueSum(vector<int> nums, int k, vector<vector<int>> edges) {
        ll n = sz(nums);
        vector<vector<ll>> a(n);
        for (int i = 1; i < n; i++) {
            ll u = edges[i - 1][0];
            ll v = edges[i - 1][1];
            a[u].push_back(v);
            a[v].push_back(u);
        }
        vector dp(n, vi(2));
        FUN([&](const auto & dfs, ll u, ll p)->void{
            dp[u][0] = nums[u];
            dp[u][1] = nums[u] ^ k;
            for (auto v : a[u]) {
                if (v == p) continue;
                dfs(v, u);
                vi ndp(2);
                ndp[0] = max(dp[v][0] + dp[u][0], dp[v][1] + dp[u][1]);
                ndp[1] = max(dp[v][1] + dp[u][0], dp[v][0] + dp[u][1]);
                dp[u]= ndp;
            }
        })(0, 0);
        return dp[0][0];
    }
};
void solve() {
    dbg(Solution().maximumValueSum({7, 7, 7, 7, 7, 7}, 3, {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}}));
}

#ifdef LOCAL
int32_t main() { solve(); }
#endif
