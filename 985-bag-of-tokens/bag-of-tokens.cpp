#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using omset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
#define vl vector<long long>
#define vi vector<int>
#define pll pair<long long, long long>
#define pii pair<int ,int>
typedef long long ll;
typedef long double ld;

const int mod = 1000000007; // 1000000007 998244353
const ll inf = 1e18;

template <typename Func> class FUN_res {Func func_; public: template <typename T>explicit FUN_res(T&& func) : func_(std::forward<T>(func)) {} template <typename... Args> decltype(auto) operator()(Args&&... args) {return func_(std::ref(*this), std::forward<Args>(args)...);}}; template <typename Func> decltype(auto) FUN(Func&& func) {return FUN_res<std::decay_t<Func>>(std::forward<Func>(func));}

class Solution {
public:
    int bagOfTokensScore(vector<int>& a, int p) {
        int i = 0, j = sz(a) - 1;
        sort(All(a));
        int sc = 0;
        while (i <= j) {
            if (p >= a[i]) sc++, p -= a[i],i++;
            else {
                if (sc == 0 || i == j) break;
                sc--;
                p += a[j];
                j--;
            }
        }
        return sc;
    }
};
void solve() {
    // dbg(Solution().maximumValueSum({7, 7, 7, 7, 7, 7}, 3, {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}}));
}

#ifdef LOCAL
int32_t main() { solve(); }
#endif
