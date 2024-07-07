/*
And you came my way on a winner's day
Shouted loudly come out and play
Can't you tell I got news for you
Sun is shining and so are you
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using omset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#define all(x) (x).begin(),(x).end()
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

template<typename T>ostream& operator<<(ostream& out, const vector<T> &vec) {for (const auto &x : vec) {out << x << " ";} out << "\n"; return out;}
template<typename T>istream& operator>>(istream& in, vector<T> &vec) {for (auto &x : vec) {in >> x;} return in;}


template<class Fun>class y_combinator_result {Fun fun_; public: template<class T>explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {} template<class ...Args>decltype(auto) operator()(Args &&...args) {return fun_(std::ref(*this), std::forward<Args>(args)...);}};
template<class Fun>decltype(auto) y_combinator(Fun &&fun) {return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));}

int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
void my_erase(omset<ll>& t, int v) {t.erase(t.find_by_order(t.order_of_key(v)));}
void my_erase(oset<ll>& t, int v) {t.erase(t.find_by_order(t.order_of_key(v)));}

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
void solve();
#ifdef ONLINE_JUDGE
int32_t main() { solve(); }
#include "debug.h"
#define dbg(...)  cerr << __LINE__ << " :: ", debug::printer(#__VA_ARGS__, __VA_ARGS__)
#define dbgA(arr, n) cerr << __LINE__ << " :: ", debug::printerArr(#arr, arr, n)
#else
#define dbg(x...)
#define dbgA(arr, n)
#endif

/*
 *  O(1) query time -> prefix sum , sparseTable (no update)
 *  O(logn) query time -> segment tree , bit (update)
 */

// solution

class Solution {
    struct Node {
        Node * tree[26];
        int cntEndWith = 0, cntPrefix = 0, cost = INT_MAX;
        bool containsKey(char ch) { return (tree[ch - 'a'] != NULL); }
        Node * get(char ch) { return tree[ch - 'a']; }
        void put(char ch, Node * node) { tree[ch - 'a'] = node;}
        void increaseEnd() { cntEndWith++;}
        void increasePrefix() { cntPrefix++; }
        void deleteEnd() { cntEndWith--; }
        void reducePrefix() { cntPrefix--;}
        int getEnd() { return cntEndWith;}
        int getPrefix() {return cntPrefix; }
    };
    Node * root;

    /** Inserts a word into the trie. */
    void insert(string word, int cost) {
        Node * node = root;
        for (auto &ch : word) {
            if (!node -> containsKey(ch)) node -> put(ch, new Node());
            node = node -> get(ch), node -> increasePrefix();
        }
        node -> cost = min(node->cost, cost);
        node -> increaseEnd();
    }
public:
    int minimumCost(string &T, vector<string>& words, vector<int>& costs) {
        ll n = sz(words);
        root = new Node();
        fo(i, n) {
            insert(words[i], costs[i]);
        }

        int M = sz(T);
        vector<ll> dp(M + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= M; i++) {
            Node* node = root;
            for (int j = i; j <= M; j++) {
                if (node->tree[T[j - 1] - 'a'] == NULL) break;
                if (node->tree[T[j - 1] - 'a']->cntEndWith > 0) {
                    // cout << i <<" "<<j<<" "<<node->tree[T[j - 1] - 'a']->cost<<endl;
                    dp[j] = min(dp[i - 1] + node->tree[T[j - 1] - 'a']->cost,dp[j]);
                }
                node = node->tree[T[j-1]-'a'];
            }
        }
        return dp[M] == INT_MAX ? -1 : dp[M];
    }
};
void solve() {}