#include <bits/stdc++.h>
using namespace std;

static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

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
#define vi vector<int>
#define pi pair<int, int>
typedef long long ll;
typedef long double ld;

const int mod = 1000000007; // 1000000007 998244353
const ll inf = INT_MAX;

template <typename Func> class FUN_res {
    Func func_;
public:
    template <typename T>
    explicit FUN_res(T&& func) : func_(std::forward<T>(func)) {}
    template <typename... Args> decltype(auto) operator()(Args&&... args) {
        return func_(std::ref(*this), std::forward<Args>(args)...);
    }
};
template <typename Func> decltype(auto) FUN(Func&& func) {
    return FUN_res<std::decay_t<Func>>(std::forward<Func>(func));
}

class Solution {
public:
    ll findCheapestPrice(int n, vector<vector<int>> e, int src, int dst, int k) {
        vector<vector<pair<ll, ll>>> a(n);
        for (auto &it : e) {
            ll x = it[0], y = it[1], w = it[2];
            a[x].emplace_back(y, w);
        }
        vector<ll> dp(n, inf);

        queue<pair<ll,ll>> q;
        q.push({src,0});
        dp[src] = 0;
        while (k >= 0 && !q.empty()) {
            ll y = sz(q);
            for (int i = 0; i < y; i++) {
                auto tp = q.front();
                q.pop();
                for (auto it : a[tp.ff]) {
                    if (dp[it.ff] > tp.ss + it.ss) {
                        dp[it.ff] = tp.ss + it.ss;
                        q.push({it.ff,dp[it.ff]});
                    }
                }
            }
            k--;
        }
        if (dp[dst] >= inf) dp[dst] = -1;
        return dp[dst];
    }
};

void solve() {
    dbg(Solution().findCheapestPrice(4, {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}}, 0, 3, 1));
}

#ifdef LOCAL
int32_t main() { solve(); return (int)0; }
#endif