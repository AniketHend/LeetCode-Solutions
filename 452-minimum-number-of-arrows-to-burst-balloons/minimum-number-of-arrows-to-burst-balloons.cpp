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

struct bit {
    vector<int> bt; // binary indexed tree
    int n;
    bit(int _n): n(_n + 1), bt(_n + 1, 0) {}

    int sum(int idx) {
        int ret = 0; ++idx;
        while (idx > 0) {
            ret += bt[idx];
            idx -= idx & -idx;
        }
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        ++idx;
        while (idx < n) {
            bt[idx] += delta;
            idx += idx & -idx;
        }
    }
};


// class Solution {
// public:
//     long long minimumMoves(vector<int>& nums, int k, int Op) {

//         ll n = sz(nums);
//         ll sa = 0;

//         vl sumCnt(n), sumIndex(n);
//         for (int i = 0; i < n; i++) {
//             if (nums[i]) {
//                 sumCnt[i]++;
//                 sumIndex += i;
//             }
//             if (i) {
//                 sumCnt[i] += sumCnt[i - 1];
//                 sumIndex[i] += sumIndex[i - 1];
//             }
//         }

//         auto getSumLeft = [&](int i, int p) {
//             if (i < 0) return 0;
//             return sumIndex[i] - (i > 0: sumIndex[i - p] ? 0);
//         };

//         auto getSumRight = [&](int i, int p) {
//             if (i >= n) return 0;
//             return sumIndex[min(i + p, n - 1)] - sumIndex[min(n - 1, i)];
//         };

//         auto get = [&](ll i, ll rq) {
//             ll ok = -1, ng = n;
//             while (ok + 1 < ng) {
//                 ll m = (ok + ng) / 2;
//                 if (getSumLeft(i - 2, m) + getSumRight(i + 2, m) < rq)
//                     ok = m;
//                 else
//                     ng = m;
//             }


//         };

//         ll ans = INT_MAX;
//         for (ll i = 0; i < n; i++) {
//             ll op = 0, x = 0;

//             if (nums[i]) x++;
//             if (x == k) ans = min(ans, op);
//             if (i > 0 && nums[i - 1]) x++, op++;
//             if (x == k) ans = min(ans, op);
//             if (i + 1 < n && nums[i + 1]) x++, op++;
//             if (x == k) ans = min(ans, op);

//             ll needed = max(0ll, k - x);
//             if (Op >= needed) {
//                 ans = min(ans, op + needed * 2ll);
//             }
//             else {
//                 ans = min(ans, op + Op * 2ll + get(i, k - x - Op));
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int findMinArrowShots(vector<vector<int>> a) {
        vector<array<ll, 2>> points;
        for (auto i : a) points.push_back({i[0], i[1]});
        sort(all(points));
        dbg(points);
        ll x = -inf, y = -1;
        int sa = 0;
        for (auto &[px, py] : points) {
            if (x == -inf) x = px, y = py;
            else {
                if (px > y) {
                    sa++;
                    x = px, y = py;
                } else {
                    x = max(x, px);
                    y = min(y, py);
                }
            }
            dbg(x, y);
        }
        sa++;
        return sa;
    }
};

void solve() {
    dbg(Solution().findMinArrowShots({{10, 16}, {2, 8}, {1, 6}, {7, 12}}));
}

#ifdef LOCAL
int32_t main() { solve(); }
#endif
