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

struct seg {
	vector<int> t, lz;
    int n;
	void push(int i, int l, int r) {
		if (lz[i]) {
			int cnt = r - l + 1;
			t[i] = cnt - t[i];
			if (l < r) {
				lz[2 * i + 1] ^= 1;
				lz[2 * i + 2] ^= 1;
			}
		}
		lz[i] = 0;
	}
	void upd(int i, int l, int r, int si, int se) {
		push(i, si, se);
		if (r < si || l > se) return;
		if (l <= si && r >= se) {
			lz[i] = 1;
			push(i, si, se);
			return;
		}
		int m = (si + se) / 2;
		upd(2 * i + 1, l, r, si, m);
		upd(2 * i + 2, l, r, m + 1, se);
		t[i] = t[2 * i + 1] + t[2 * i + 2];
	}
	int query(int i, int l, int r, int si, int se) {
		push(i, si, se);
		if (r < si || l > se) return 0;
		if (l <= si && r >= se) {
			return t[i];
		}
		int m = (si + se) / 2;
		int x = query(2 * i + 1, l, r, si, m);
		int y = query(2 * i + 2, l, r, m + 1, se);
		return x + y;
	}
	int query(int l, int r) {
		return query(0, l, r, 0, n - 1);
	}
	void build(int i, int l, int r, vi & nums) {
		if (l == r) {
			t[i] = nums[l];
			return;
		}
		build(2 * i + 1, l, (l + r) / 2, nums);
		build(2 * i + 2, (l + r) / 2 + 1, r, nums);
		t[i] = t[2 * i + 1] + t[2 * i + 2];
	}
	void init(vector<int> & arr) {
		n = arr.size();
		t.assign(4 * n,0);
		lz.assign(4 * n,0);
		build(0, 0, n - 1,arr);
	}
};

// solution
class Solution {
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        ll cur_q = 0;
        vector<ll> sa;
        ll N = sz(nums1);
        seg sg;
        sg.init(nums1);
        ll sum = accumulate(all(nums2), 0LL);

        for (auto &q : queries) {
            int type = q[0];
            int l = q[1];
            int r = q[2];
            if (type == 1) {
                sg.upd(0, l, r, 0, N - 1);
            } else if (type == 2) {
                cur_q += sg.query(0,N-1) * 1LL * l;
            } else if (type == 3) {
                sa.push_back(cur_q + sum);
            } else {
                assert(false);
            }
        }
        return sa;
    }
};

void solve() {}
#ifdef LOCAL
int32_t main() { solve(); }
#endif
