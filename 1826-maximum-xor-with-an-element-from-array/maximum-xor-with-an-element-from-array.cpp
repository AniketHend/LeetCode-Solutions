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

// solution
class Solution {
    template <class T, int B> struct bit_trie {
        vector<array<long long, 2>> trie = {{0, 0}};
        vector<long long> cnt = {0};

        bit_trie() {}

        bit_trie(int elements) {
            trie.reserve(elements * B);
            cnt.reserve(elements * B);
        }

        void update(T val, int delta) {
            int node = 0;
            for (int i = B - 1; i >= 0; i--) {
                int c = val & (1ll << i) ? 1 : 0;
                if (!trie[node][c]) {
                    trie[node][c] = trie.size();
                    trie.push_back({0, 0});
                    cnt.push_back(0);
                }
                node = trie[node][c];
                cnt[node] += delta;
            }
        }

        void insert(T val) { update(val, 1); }

        void erase(T val) { update(val, -1); }

        T max(T val) {
            // Find max of val XOR element
            T res = 0;
            int node = 0;
            for (int i = B - 1; i >= 0; i--) {
                int c = val & (1ll << i) ? 0 : 1;
                if (trie[node][c] && cnt[trie[node][c]]) {
                    res ^= 1ll << i;
                    node = trie[node][c];
                } else
                    node = trie[node][c ^ 1];
            }
            return res;
        }

        T min(T val) {
            // Find min of val XOR element
            T res = 0;
            int node = 0;
            for (int i = B - 1; i >= 0; i--) {
                int c = val & (1ll << i) ? 1 : 0;
                if (trie[node][c] && cnt[trie[node][c]])
                    node = trie[node][c];
                else {
                    res ^= 1ll << i;
                    node = trie[node][c ^ 1];
                }
            }
            return res;
        }

        int less_than(T val, T limit) {
            // How many elements satisfy val XOR element < limit ?
            int res = 0, node = 0;
            for (int i = B - 1; i >= 0; i--) {
                int c = val & (1ll << i) ? 1 : 0;
                if (limit & (1ll << i)) {
                    res += cnt[trie[node][c]];
                    if (trie[node][c ^ 1] && cnt[trie[node][c ^ 1]])
                        node = trie[node][c ^ 1];
                    else
                        break;
                } else {
                    if (trie[node][c] && cnt[trie[node][c]])
                        node = trie[node][c];
                    else
                        break;
                }
            }
            return res;
        }
    };

public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<array<int, 3>> Q;
        for (int i = 0; i < sz(queries); ++i) {
            Q.push_back({queries[i][1], queries[i][0], i});
        }
        sort(all(Q));
        sort(all(nums));
        vi ans(sz(Q));
        bit_trie<ll, 31> bt(sz(nums));
        int i = 0;
        for (auto &[mi, xi, ind] : Q) {
            while (i < sz(nums) && nums[i] <= mi) bt.insert(nums[i++]);
            ans[ind] = bt.max(xi);
            if(i == 0) {
                ans[ind] = -1;
            }
        }
        return ans;
    }
};
void solve() {}
#ifdef LOCAL
int32_t main() { solve(); }
#endif
