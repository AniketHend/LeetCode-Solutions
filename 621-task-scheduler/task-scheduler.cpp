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
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x.size())
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
    int leastInterval(vector<char>& tasks, int n) {
        int max_freq = 0, sz = tasks.size();
        int freq[26] = {0};
        for (char c : tasks) {
            int f = ++freq[c - 'A'];
            max_freq = max(max_freq, f);
        }
        int num_maxFreq = count(freq, freq + 26, max_freq);
        int time = (max_freq - 1) * (n + 1) + num_maxFreq;
        return max(time, sz);
    }
};

void solve() {
    // dbg(Solution().leastInterval({1, 0, 1, 0, 1}, 3, 0));
}

#ifdef LOCAL
int32_t main() { solve(); }
#endif
