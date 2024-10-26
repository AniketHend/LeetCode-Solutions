class Solution {
public:
#define ll int
#define v vector
#define vi vector<ll>
#define pll pair<ll, ll>
#define pb push_back
#define nl '\n'
#define f(k, m, n) for (ll k = m; k < n; k++)
#define rf(k, m, n) for (ll k = m; k >= n; k--)
#define andd &&
#define all(arr) arr.begin(), arr.end()
#define F first
#define S second
#define sp ' '
#define yes cout << "YES\n";
#define no cout << "NO\n";

    struct node {
        ll mintill;
        vi next;
        node() {
            mintill = INT_MAX;
            f(i, 0, 2) { next.emplace_back(-1); }
        }
    };

    v<node> t;

    void insert(ll n) {
        ll node = 0;
        t[0].mintill = min(t[0].mintill, n);
        rf(i, 31, 0) {
            bool idx = (n >> i) & 1;
            if (t[node].next[idx] == -1) {
                t[node].next[idx] = t.size();
                t.emplace_back();
            }
            node = t[node].next[idx];
            t[node].mintill = min(t[node].mintill, n);
        }
    }

    ll check(ll n, ll q) {
        ll node = 0;
        ll ans = -1;
        rf(i, 31, 0) {
            ll want = ((n & (1ll << i)) == 0);
            if (t[node].next[want] != -1) {
                if (t[t[node].next[want]].mintill <= q) {
                    if (ans == -1)
                        ans = (1ll << i);
                    else
                        ans |= (1ll << i);
                    node = t[node].next[want];
                    continue;
                }
            }
            // cout << node << " "<< want<<" "<<t[node].next[0]<<" "<<t[node].next[1] << endl;
            want = 1 - want;
            if (t[node].next[want] != -1) {
                if (t[t[node].next[want]].mintill <= q) {
                    node = t[node].next[want];
                    continue;
                }
            }
            return -1;
        }
        return max(0,ans);
    }
    vector<int> maximizeXor(vector<int>& arr, vector<vector<int>>& queries) {
        ll n = arr.size();
        t.clear();
        t.emplace_back();
        f(i, 0, n) { insert(arr[i]); }
        vi ans;
        for (auto x : queries) {
            ans.pb(check(x[0], x[1]));
        }
        return ans;
    }
};