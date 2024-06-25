#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using oset =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using omset = tree<T, null_type, less_equal<T>, rb_tree_tag,
      tree_order_statistics_node_update>;

static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#define ff first
#define ss second
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define vi vector<int>
#define vl vector<long long>
#define vii vector<vector<int>>
#define vll vector<vector<long long>>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define sz(x) (int)(x.size())
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define up(a) transform(all(a), a.begin(), ::toupper)
#define low(a) transform(all(a), a.begin(), ::tolower)
#define sum(nums, x) accumulate(nums.begin(), nums.end(), x)
#define tobin(n) bitset<64>(n).to_string().substr(64 - (int)(log2(n)) - 1)
#define LSB(n) (63 - __builtin_clzll(n)) /* leftmost set bit */
#define RSB(n) __builtin_ctzll(n)        /* rightmost set bit */
#define BTS(n) __builtin_popcount(n)

typedef long long ll;
typedef long double ld;

template <class T> using pqmin = priority_queue<T, vector<T>, greater<T>>;
template <class T> using pqmax = priority_queue<T>;
template <class T> void print(vector<T>& a) {
    for (auto& x : a) {
        cout << x << " ";
    }
    cout << endl;
}

const int mod = 1000000007; // 1000000007 998244353
const ll lnf = 1e18;
const int inf = INT_MAX;

int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
void my_erase(omset<ll>& t, int v) {
    t.erase(t.find_by_order(t.order_of_key(v)));
}
void my_erase(oset<ll>& t, int v) {
    t.erase(t.find_by_order(t.order_of_key(v)));
}

struct Compress {
    vl a;
    int cnt;
    Compress() : cnt(0) {}
    void add(ll x) { a.push_back(x); }
    void init() {
        sort(all(a));
        a.erase(unique(all(a)), a.end());
        cnt = sz(a);
    }
    ll to(ll x) {
        int index = lower_bound(all(a), x) - a.begin();
        return index;
    }
    ll from(int x) { return a[x]; }
    int size() { return cnt; }
};

#ifdef ONLINE_JUDGE
#include "debug.h"
#define dbg(...)                                                               \
    cerr << __LINE__ << " :: ", debug::printer(#__VA_ARGS__, __VA_ARGS__)
#define dbgA(arr, n) cerr << __LINE__ << " :: ", debug::printerArr(#arr, arr, n)
#else
#define dbg(x...)
#define dbgA(arr, n)
#endif

/*
    #define int long long
    #undef int
*/

/*
    auto operation = [&](const int& x, const int& y) {return (x * 1ll * y);};
    SGT<int, decltype(operation)>sgt(n, operation);
    sgt.build(a);
*/
template <typename value_t, class merge_t> class SGT {
    int n;
    vector<value_t> t; // root starts at 1
    merge_t merge;     // associative function for SGT
public:
    explicit SGT(int _n, const merge_t& _merge = merge_t{})
        : n{_n}, t(2 * n), merge{_merge} {}
    void modify(int p, const value_t& x) {
        for (t[p += n] = x; p > 1; p >>= 1)
            t[p >> 1] = merge(t[p], t[p ^ 1]);
    }
    value_t query(int l, int r, value_t init) { // [l:r)#
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                init = merge(init, t[l++]);
            if (r & 1)
                init = merge(init, t[--r]);
        }
        return init;
    }
};

// solution
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        ll n = sz(s);

        vector<int> end(26, n);
        vector<int> pre(26, -1);
        for (int i = 0; i < n; i++)
            end[s[i] - 'a'] = i;
        for (int i = n - 1; i >= 0; i--)
            pre[s[i] - 'a'] = i;

        vector<vector<int>> ch(26);
        for (int i = 0; i < n; ++i) {
            ch[s[i] - 'a'].push_back(i);
        }

        for (int i = 0; i < 26; i++) {
            if (ch[i].size() == 0)
                continue;
            int x = end[i];
            int y = pre[i];
            for (int j = 0; j < 26; j++) {
                if (ch[j].size() == 0)
                    continue;
                int index = upper_bound(all(ch[j]), pre[i]) - ch[j].begin();
                if (index == ch[j].size())
                    continue;
                if (ch[j][index] > pre[i] && ch[j][index] < end[i]) {
                    x = max(x, end[j]);
                    y = min(y, pre[j]);
                }
            }
            pre[i] = min(pre[i], y);
            end[i] = max(end[i], x);
        }

        for (int i = 0; i < 26; i++) {
            if (ch[i].size() == 0)
                continue;
            int x = end[i];
            int y = pre[i];
            for (int j = 0; j < 26; j++) {
                if (ch[j].size() == 0)
                    continue;
                int index = upper_bound(all(ch[j]), pre[i]) - ch[j].begin();
                if (index == ch[j].size())
                    continue;
                if (ch[j][index] > pre[i] && ch[j][index] < end[i]) {
                    x = max(x, end[j]);
                    y = min(y, pre[j]);
                }
            }
            pre[i] = min(pre[i], y);
            end[i] = max(end[i], x);
        }

        // for (int i = 0; i < 26; i++) {
        //     cout << pre[i] << " " << end[i] << endl;
        // }

        vector<pair<int, int>> dp(n + 1, { 0, 0});
        for (int i = n - 1; i >= 0; i--) {
            auto skip = dp[i + 1];
            if (pre[s[i] - 'a'] == i) {
                auto can = dp[end[s[i] - 'a'] + 1];
                int len = (end[s[i] - 'a'] - i + 1);
                can.first += 1;
                can.second += len;
                if (can.first != skip.first) {
                    if (can.first < skip.first)
                        dp[i] = skip;
                    else dp[i] = can;
                } else {
                    if (can.second < skip.second) {
                        dp[i] = can;
                    }
                    else dp[i] = skip;
                }
            } else {
                dp[i] = skip;
            }
        }

        vector<string> st;
        auto g = [&](auto g_, int i) -> void {
            if (i >= n)
                return;

            auto here = dp[i];
            pair<int, int> c = {INT_MIN, INT_MAX};
            auto d = dp[i + 1];
            if (pre[s[i] - 'a'] == i) {
                c = dp[end[s[i] - 'a'] + 1];
                c.first++;
                c.second += (end[s[i] - 'a'] - i + 1);
            }

            if (c.first == here.first) {
                if (d.first == here.first) {
                    if (c.second < d.second) {
                        st.push_back(s.substr(i, end[s[i] - 'a'] - i + 1));
                        g_(g_, end[s[i] - 'a'] + 1);
                    } else {
                        g_(g_, i + 1);
                    }
                } else {
                    st.push_back(s.substr(i, end[s[i] - 'a'] - i + 1));
                    g_(g_, end[s[i] - 'a'] + 1);
                }
            } else {
                g_(g_, i + 1);
            }
            return;
        };
        g(g, 0);
        return st;
    }
};
void solve() {}
#ifdef LOCAL
int32_t main() { solve(); }
#endif
