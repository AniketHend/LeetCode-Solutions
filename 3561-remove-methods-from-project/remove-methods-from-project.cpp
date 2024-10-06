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
void dfs(int source, vector<vector<int>>& a, vector<int>&vis) {
        vis[source] = 1;
        for (auto& it : a[source]) {
            if (vis[it] == 0) {
                dfs(it, a,vis);
           }
        }
    }

// solution
class Solution {
public:
  vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
    vector<vector<int>> a(n), b(n);
    for (auto &e : invocations) {
      a[e[0]].push_back(e[1]);
    }
    for (auto &e : invocations) {
      b[e[1]].push_back(e[0]);
    }

    vector<int> can(n);
    dfs(k,a,can);
    // queue<int> q;
    // q.push(k);
    // while (!q.empty()) {
    //   int pt = q.front(); q.pop();
    //   can[pt] = 1;
    //   for (auto v : a[pt]) {
    //     if (!can[v]) {
    //     //   can[v] = 1;
    //       q.push(v);
    //     }
    //   }
    // }
    // dfs(k)
    vector<int> rem;
    vector<int> dp(n,1);
    
      int ok=0;
    for (int i = 0; i < n; ++i) {
      if(!can[i]) continue;
      for (auto v : b[i]) {
        if (!can[v]) {
          ok = 1;break;
        }
      }      
      if(ok)break;
    }
    for(int i=0;i<n;i++) {
      if(can[i] && ok) rem.push_back(i);
      else if(!can[i]) rem.push_back(i);
    }
    return rem;
  }
};

void solve() {

}

#ifdef LOCAL
int32_t main() { solve(); }
#endif
