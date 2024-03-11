#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using omset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

static const int _ = []() {ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0;}();

#ifdef ONLINE_JUDGE
#include "debug.h"
#define dbg(...) cerr << __LINE__ << " :: ", _DEBUG_UTIL_::printer(#__VA_ARGS__, __VA_ARGS__)
#define dbgA(arr, n) cerr << __LINE__ << " :: ", _DEBUG_UTIL_::printerArr(#arr, arr, n)
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
#define vll vector<vector<long long>>
#define vii vector<vector<int>>
#define pll pair<long long, long long>
#define pii pair<int ,int>
typedef long long ll;
typedef long double ld;

const int mod = 1000000007; // 1000000007 998244353
const ll inf = 1e18;

class Solution {
public:
    string customSortString(string order, string s) {
        vi c(26, -1);
        for (int i = 0; i < sz(order); i++) {
            c[order[i] - 'a'] = i;
        }
        string t="",u="";
        for(auto i:s) {
            if(c[i-'a']==-1) u+=i;
            else t+=i;
        }
        sort(All(t), [&](char x, char y) {
            return c[x - 'a'] < c[y - 'a'];
        });
        return u+t;
    }
};
void solve() {
    // dbg(Solution().shortestSubstrings({"vbb", "grg", "lexn", "oklqe", "yxav"}));
}

#ifdef LOCAL
int32_t main() { solve(); }
#endif
