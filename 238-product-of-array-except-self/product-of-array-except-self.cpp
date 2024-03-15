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
    vector<int> productExceptSelf(vector<int>& nums) {
        ll n = sz(nums);
        vi pf(n),sf(n);
        pf[0]=nums[0],sf[n-1]=nums[n-1];
        for(int i=1;i<n;i++) {
            pf[i]=pf[i-1]*nums[i];
        }
        for(int i=n-2;i>=0;i--) {
            sf[i]=sf[i+1]*nums[i];
        }
        vi res;
        for(int i=0;i<n;i++) {
            ll cr=1;
            if(i>0) cr*=pf[i-1];
            if(i+1<n) cr*=sf[i+1];
            res.push_back(cr);
        }
        return res;
    }
};
void solve() {
    dbg(Solution().);
}

#ifdef LOCAL
int32_t main() { solve(); }
#endif
