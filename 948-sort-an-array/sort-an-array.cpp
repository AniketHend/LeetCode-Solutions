#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using omset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

static const int _ = []() {ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0;}();

#define all(x) (x).begin(),(x).end()
#define uniqque(x) sort(all(x)); x.erase(unique(all(x)),x.end())
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define endl '\n'
#define fo(i,n) for(int i=0;i<n;++i)
#define forr(i,n) for(int i=n-1;i>=0;--i)
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=b;i>=a;--i)

#define ffs(a) __builtin_ffs(a) // find first set
#define clz(a) __builtin_clz(a) // count leading zeroes
#define ctz(a) __builtin_ctz(a) // count trailing zeroes
#define popc(a) __builtin_popcount(a) // count set bits
#define popcll(a) __builtin_popcountll(a) //count set bits for long long int

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

const ll inf = 1e9;
const ld eps = 1e-9;
const ld pi = acos(-1);
const int mod = 1000000007; // 1000000007 998244353
const ll lnf = 1e18;

template <class T> using pqmin = priority_queue<T, vector<T>, greater<T>>;
template <class T> using pqmax = priority_queue<T>;

template<class T, class V> istream& operator>> (istream& is, std::pair<T, V>& p) {is >> p.first >> p.second; return is;}
template<class T, class V>  ostream& operator<< (ostream& is, std::pair<T, V>& p) {is << p.first << " " << p.second; is << endl; return is;}
template<class T> istream& operator>> (istream& is, std::vector<T>& p) {  for (auto &i : p) {is >> i;} return is;}
template<class T> ostream& operator<< (ostream& is, std::vector<T>& p) {  for (auto &i : p) {is << i << " ";} is << endl; return is;}
template<class T> istream& operator>> (istream& is, std::vector<std::vector<T>>& p) {  for (auto &i : p) {is >> i;} return is;}
template<class T> ostream& operator<< (ostream& is, std::vector<std::vector<T>>& p) {  for (auto &i : p) {is << i << " ";} is << endl; return is;}

template<class Fun>class y_combinator_result {Fun fun_; public: template<class T>explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {} template<class ...Args>decltype(auto) operator()(Args &&...args) {return fun_(std::ref(*this), std::forward<Args>(args)...);}};
template<class Fun>decltype(auto) y_combinator(Fun &&fun) {return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));}

int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
void my_erase(omset<ll>& t, int v) {t.erase(t.find_by_order(t.order_of_key(v)));}
void my_erase(oset<ll>& t, int v) {t.erase(t.find_by_order(t.order_of_key(v)));}

// O(1) query with no updates
struct sparseTable {
  int n, k; vector< vector<long long> > table; vector<long long> logs;
  void init(int x) {n = x; logs.resize(n + 1); logs[1] = 0; for (int i = 2; i <= n; i++) {logs[i] = logs[i / 2] + 1;} k = *max_element(logs.begin(), logs.end()); table.assign(k + 1, vector<long long> (n + 1, INT_MAX) );}
  long long operation(long long x, long long y) {return (x & y);}
  void build(vector<int> &arr) {for (int i = 0; i < arr.size(); i++) {table[0][i] = arr[i];} for (int j = 1; j <= k; j++) {for (int i = 0; i + (1ll << j) <= n; i++) {table[j][i] = operation(table[j - 1][i], table[j - 1][i + (1ll << (j - 1))]);}}}
  long long query(int l , int r) {int j = logs[r - l + 1]; long long answer = operation(table[j][l], table[j][r - (1ll << j) + 1]); return answer;}
};
/* sparseTable sp; sp.init(n); sp.build(a); */

// O(logn) query O(logn) range updates
template<typename node, typename upd> struct LAZY {
  vector<node> ST; vector<bool> LT; vector<upd> UT; vector<int> arr; int n, s;
  LAZY(vector<int> &a) {arr = a, n = a.size(), s = 1; while (s < 2 * n) {s = s << 1;} ST.resize(s); fill(ST.begin(), ST.end(), node()); LT.resize(s); fill(LT.begin(), LT.end(), false); UT.resize(s); fill(UT.begin(), UT.end(), upd()); build(0, n - 1, 1);}
  void build(int s, int e, int i) {if (s == e)   {ST[i] = node(arr[s]); return;} int m = (s + e) / 2; build(s, m, 2 * i); build(m + 1, e, 2 * i + 1); ST[i].merge(ST[2 * i], ST[2 * i + 1]);}
  void pushdown(int i, int s, int e) {if (LT[i]) {int m = (s + e) / 2; apply(2 * i, s, m, UT[i]); apply(2 * i + 1, m + 1, e, UT[i]); UT[i] = upd(), LT[i] = 0;}}
  void apply(int i, int s, int e, upd& u) {if (s != e) {LT[i] = 1, UT[i].comb(u, s, e);} u.apply(ST[i], s, e);}
  void update(int s, int e, int i, int l, int r, upd& u) {if (s > r || e < l) return; if (s >= l && e <= r) {apply(i, s, e, u); return;} pushdown(i, s, e); int m = (s + e) / 2; update(s, m, 2 * i, l, r, u); update(m + 1, e, 2 * i + 1, l, r, u); ST[i].merge(ST[2 * i], ST[2 * i + 1]);}
  node query(int s, int e, int i, int l, int r) {if (s > r || e < l) return node(); if (s >= l && e <= r) {pushdown(i, s, e); return ST[i];} pushdown(i, s, e); int m = (s + e) / 2; node ln, rn, ans; ln = query(s, m, 2 * i, l, r); rn = query(m + 1, e, 2 * i + 1, l, r); ans.merge(ln, rn); return ans;}
  void change(int l, int r, int val) {upd x = upd(val); update(0, n - 1, 1, l, r, x);}
  node get(int l, int r) {return query(0, n - 1, 1, l, r);}
};
// LAZY<int,node,update>sg = LAZY<int,node,update>(a);

template<typename node, typename upd>
struct TREE {
  vector<node> ST; vector<int> arr; int n; int s;
  TREE(int sz, vector<int> &a) {arr = a, n = sz, s = 1; while (s < 2 * n) {s = s << 1;} ST.resize(s); fill(ST.begin(), ST.end(), node()); build(0, n - 1, 1);}
  void build(int s, int e, int i)  {if (s == e) {ST[i] = node(arr[s]); return;} int mid = (s + e) / 2; build(s, mid, 2 * i); build(mid + 1, e, 2 * i + 1); ST[i].merge(ST[2 * i], ST[2 * i + 1]);}
  void update(int s, int e, int i, int qi, upd &u)  {if (s == e) {u.apply(ST[i]); return;} int mid = (s + e) / 2; if (mid >= qi) {update(s, mid, 2 * i, qi, u);} else {update(mid + 1, e, 2 * i + 1, qi, u);} ST[i].merge(ST[2 * i], ST[2 * i + 1]);}
  node query(int s, int e, int i, int l, int r) { if (s > r || e < l) return node(); if (s >= l && e <= r) return ST[i]; int mid = (s + e) / 2; node ln, rn, ans; ln = query(s, mid, 2 * i, l, r); rn = query(mid + 1, e, 2 * i + 1, l, r); ans.merge(ln, rn); return ans;}
  void change(int i, int val) {upd x = upd(val); update(0, n - 1, 1, i, x);}
  node get(int l, int r) {return query(0, n - 1, 1, l, r);}
};
// TREE<T, U>sg = TREE<T, U>(n, a);

struct node {
  int val;
  node() {val = 0;}
  node(int p1) {val = p1;}
  void merge(node &left, node &right) { val = max(left.val , right.val);}
};
struct update {
  int val;
  update() {val = 0;}
  update(int val1) {val = val1;}
  void apply(node &a, int s, int e) {a.val += val;}  // range update
  void apply(node &a) {a.val = val;} // point update
  void comb(update& x, int s, int e) {val += x.val;}
};

struct Compress {
  vl a; int cnt;
  Compress() : cnt(0) {}
  void add(ll x) { a.push_back(x); }
  void init() {sort(all(a)); a.erase(unique(all(a)), a.end()); cnt = sz(a);}
  ll to(ll x) {int index = lower_bound(all(a), x) - a.begin(); return index;}
  ll from(int x) { return a[x]; }
  int size() { return cnt; }
};

#ifdef ONLINE_JUDGE
#include "debug.h"
#define dbg(...)  cerr << __LINE__ << " :: ", debug::printer(#__VA_ARGS__, __VA_ARGS__)
#define dbgA(arr, n) cerr << __LINE__ << " :: ", debug::printerArr(#arr, arr, n)
#else
#define dbg(x...)
#define dbgA(arr, n)
#endif

// solution
const static auto initialize = [] {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

constexpr int LIMIT = 8;

class Solution {
  void bubble_sort(vector<int>& nums, const int begin, const int end) const {
    bool repeat = true;
    while (repeat) {
      repeat = false;
      for (int i = begin; i + 1 < end; i++) {
        if (nums[i + 1] < nums[i]) {
          swap(nums[i + 1], nums[i]);
          repeat = true;
        }
      }
    }
  }

  void bubble_sort(vector<int>& nums) const {
    bubble_sort(nums, 0, nums.size());
  }

  void select_sort(vector<int>& nums) const {
    for (int i = 0; i + 1 < nums.size(); ++i) {
      for (int j = i + 1; j < nums.size(); ++j) {
        if (nums[j] < nums[i])
          swap(nums[j], nums[i]);
      }
    }
  }

  void quick_sort(vector<int>& nums, vector<int>& data,
                  const int begin) const {
    if (data.size() < LIMIT) {
      bubble_sort(data);
      if (&nums == &data)
        return;
      int j = begin;
      for (int i = 0; i < data.size();)
        nums[j++] = data[i++];
      return;
    }

    const int PIVOT =
      (data[0] + data[data.size() / 2] + data[data.size() - 1]) / 3;

    vector<int> smaller;
    vector<int> equal;
    vector<int> greater;

    for (int i = 0; i < data.size(); ++i) {
      if (data[i] < PIVOT)
        smaller.push_back(data[i]);
      else if (PIVOT < data[i])
        greater.push_back(data[i]);
      else
        equal.push_back(data[i]);
    }

    int j = begin + smaller.size();
    for (int i = 0; i < equal.size();)
      nums[j++] = equal[i++];

    quick_sort(nums, smaller, begin);
    quick_sort(nums, greater, begin + smaller.size() + equal.size());
  }

  void quick_sort(vector<int>& nums) const { quick_sort(nums, nums, 0); }

  void merge_sort(vector<int>& nums, const int begin, const int end) const {
    if (end - begin < LIMIT) {
      bubble_sort(nums, begin, end);
      return;
    }

    const int half = (end - begin) / 2 + begin;

    merge_sort(nums, begin, half);
    merge_sort(nums, half, end);

    vector<int> tmp(nums.begin() + begin, nums.begin() + half);

    int i = 0;
    int j = half;
    int k = begin;
    while (i < tmp.size() and j < end) {
      if (tmp[i] < nums[j])
        nums[k++] = tmp[i++];
      else
        nums[k++] = nums[j++];
    }

    while (i < tmp.size())
      nums[k++] = tmp[i++];
  }

  void merge_sort(vector<int>& nums) const {
    merge_sort(nums, 0, nums.size());
  }

  void min_max(const vector<int>& nums, int& MIN, int& MAX) const {
    MIN = nums[0];
    MAX = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > MAX)
        MAX = nums[i];
      else if (nums[i] < MIN)
        MIN = nums[i];
    }
  }

  int index(const int MIN, const int MAX, const int size,
            const int val) const {
    return size * (long int)(val - MIN) / (MAX - MIN + 1);
  }

  void bucket_sort(vector<int>& nums, const int MIN, const int MAX) const {
    const int BUCKET = nums.size();
    vector<vector<int>> data(BUCKET);
    for (int i : nums)
      data[index(MIN, MAX, BUCKET, i)].push_back(i);

    int j = 0;
    for (auto& it : data) {
      counting_sort(it);
      for (int i : it)
        nums[j++] = i;
    }
  }

  void bucket_sort(vector<int>& nums) const {
    if (nums.size() < LIMIT) {
      bubble_sort(nums);
      return;
    }

    int MIN, MAX;
    min_max(nums, MIN, MAX);

    bucket_sort(nums, MIN, MAX);
  }

  void counting_sort(vector<int>& nums, const int MIN, const int MAX) const {
    const int BUCKET = MAX - MIN + 1;

    vector<int> data(BUCKET, 0);
    for (int i : nums)
      ++data[i - MIN];

    int k = 0;
    for (int i = 0; i < BUCKET; ++i) {
      for (int j = 0; j < data[i]; ++j)
        nums[k++] = i + MIN;
    }
  }

  void counting_sort(vector<int>& nums) const {
    if (nums.size() < LIMIT) {
      bubble_sort(nums);
      return;
    }

    int MIN, MAX;
    min_max(nums, MIN, MAX);

    counting_sort(nums, MIN, MAX);
  }

  void count_buck_sort(vector<int>& nums) const {
    if (nums.size() < LIMIT) {
      bubble_sort(nums);
      return;
    }

    int MIN, MAX;
    min_max(nums, MIN, MAX);

    if (MAX > nums.size() * log2(nums.size()) + MIN)
      bucket_sort(nums, MIN, MAX);
    else
      counting_sort(nums, MIN, MAX);
  }

public:
  vector<int> sortArray(vector<int>& nums) const {
    // count_buck_sort(nums);
    sort(nums.begin(), nums.end());
    return nums;
  }
};
void solve() {
}
#ifdef LOCAL
int32_t main() { solve(); }
#endif

// 0, cor[arr[i]] - 1
// cor[arr[i]] += 1