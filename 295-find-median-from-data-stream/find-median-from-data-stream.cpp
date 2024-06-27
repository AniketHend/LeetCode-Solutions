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
class MedianFinder {
    priority_queue<int> pqmin;
    priority_queue<int, vector<int>, greater<int>> pqmax;
    int n;
    int flag;
    // 1234
    // 2 1
    // 2 3
public:
    MedianFinder() {}
    void addNum(int num) {
        pqmax.push(num);
        if (sz(pqmin) != sz(pqmax)) {
            pqmin.push(pqmax.top()); pqmax.pop();
        }

        if (!pqmax.empty() && !pqmin.empty()) {
            pqmax.push(pqmin.top()); pqmin.pop();
            pqmin.push(pqmax.top()); pqmax.pop();
        }
        dbg(pqmin, pqmax);
    }

    double findMedian() {
        //even case
        if (pqmin.size() != pqmax.size()) return pqmin.top();
        return (double)(pqmin.top() + pqmax.top()) / (double)2;
    }
};

void solve() {
    MedianFinder obj =  MedianFinder();
    for (int i = -1; i >= -5; i--) {
        obj.addNum(i);
        dbg(obj.findMedian());
    }
    // dbg(obj.findMedian());
}
#ifdef LOCAL
int32_t main() { solve(); }
#endif
