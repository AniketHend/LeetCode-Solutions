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
const int dx[] = { -1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
// int drow[8] = { -1, -1, -1, 0, 0, 1, 1, 1};
// int dcol[8] = { -1, 0, 1, -1, 1, -1, 0, 1};

template <class T> using pqmin = priority_queue<T, vector<T>, greater<T>>;
template <class T> using pqmax = priority_queue<T>;

template<class T, class V> istream& operator>> (istream& is, std::pair<T, V>& p) {is >> p.first >> p.second; return is;}
template<class T, class V>  ostream& operator<< (ostream& is, std::pair<T, V>& p) {is << p.first << " " << p.second; is << endl; return is;}
template<class T> istream& operator>> (istream& is, std::vector<T>& p) {  for (auto &i : p) {is >> i;} return is;}
template<class T> ostream& operator<< (ostream& is, std::vector<T>& p) {  for (auto &i : p) {is << i << " ";} is << endl; return is;}
template<class T> istream& operator>> (istream& is, std::vector<std::vector<T>>& p) {  for (auto &i : p) {is >> i;} return is;}
template<class T> ostream& operator<< (ostream& is, std::vector<std::vector<T>>& p) {  for (auto &i : p) {is << i << " ";} is << endl; return is;}

template<class Fun> class y_combinator_result {Fun fun_; public: template<class T>explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {} template<class ...Args>decltype(auto) operator()(Args &&...args) {return fun_(std::ref(*this), std::forward<Args>(args)...);}};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) {return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));}

void my_erase(omset<int>& t, int v) {t.erase(t.find_by_order(t.order_of_key(v)));}
void my_erase(oset<ll>& t, int v) {t.erase(t.find_by_order(t.order_of_key(v)));}

struct cord_comp {
  cord_comp() : cnt(0) {}
  void add(ll x) { a.push_back(x); }
  void init() {sort(a.begin(), a.end()); a.erase(unique(a.begin(), a.end()), a.end()); cnt = (int)(a.size());}
  ll to(ll x) {int index = lower_bound(a.begin(), a.end(), x) - a.begin(); return index;}
  ll from(int x) { return a[x]; }
  int size() { return cnt; }
private:
  vector<ll> a; int cnt;
};

#ifdef ONLINE_JUDGE
#include "debug.h"
#define dbg(...)  cerr << __LINE__ << " :: ", debug::printer(#__VA_ARGS__, __VA_ARGS__)
#define dbgA(arr, n) cerr << __LINE__ << " :: ", debug::printerArr(#arr, arr, n)
#else
#define dbg(x...)
#define dbgA(arr, n)
#endif

string toBin(int a) {return bitset<10>(a).to_string();}
int toDec(string a) {return (int)bitset<32>(a).to_ullong();}

// -3 (-1 -2)
class Solution {
public:
  vector<int> maxTargetNodes(vector<vector<int>>& e1, vector<vector<int>>& e2, int k) {
    int n1 = sz(e1) + 1;
    int n2 = sz(e2) + 1;

    vector<vector<vector<int>>> g(2, vector<vector<int>>(max(n1, n2)));

    for (auto e : e1) {
      g[0][e[0]].push_back(e[1]);
      g[0][e[1]].push_back(e[0]);
    }
    for (auto e : e2) {
      g[1][e[0]].push_back(e[1]);
      g[1][e[1]].push_back(e[0]);
    }

    vector<int> sa(n1);

    // distance <= k-1
    int mx = 0;

    for (int node = 0; node < n2; ++node) {
      vector<int> dis(n2, -1), q(1, node);
      dis[node] = 0;
      for (int i = 0; i < sz(q); ++i) {
        for (auto v : g[1][q[i]]) {
          if (dis[v] == -1) {
            dis[v] = dis[q[i]] + 1;
            if (dis[v] >= k) continue;
            q.push_back(v);
          }
        }
      }
      // cout << node << endl;
      // cout << dis;
      int now = 0;
      for (int i = 0; i < n2; i++) now += (dis[i] <= k - 1 && dis[i] != -1);
      // cout << now << endl<<endl;
      mx = max(mx, now);
    }
    
    // cout << mx << endl<<endl;

    for (int node = 0; node < n1; node++) {

      vector<int> dis(n1, -1), q(1, node);
      dis[node] = 0;
      for (int i = 0; i < sz(q); ++i) {
        for (auto v : g[0][q[i]]) {
          if (dis[v] == -1) {
            dis[v] = dis[q[i]] + 1;
            if (dis[v] > k) continue;
            q.push_back(v);
          }
        }
      }
      int now = 0;
      for (int i = 0; i < n1; i++) now += (dis[i] <= k && dis[i] != -1);

      sa[node] += now;
      sa[node] += mx;
    }

    return sa;

  }
};
void solve() {
}

#ifdef LOCAL
int32_t main() { solve(); }
#endif
