typedef long long ll;
struct sparseTable {
    int n, k;
    vector< vector<ll> > table;
    vector<ll> logs;

    void init(int x) {
        n = x;
        logs.resize(n + 1);
        logs[1] = 0;
        for (int i = 2; i <= n; i++)
            logs[i] = logs[i / 2] + 1;
        k = *max_element(logs.begin(), logs.end());
        table.assign(k + 1, vector<ll> (n + 1, INT_MAX) );
    }

    ll operation(ll x, ll y) {
        return (x & y);
    }

    void build(vector<int> &arr) {
        for (int i = 0; i < arr.size(); i++)
            table[0][i] = arr[i];
        for (int j = 1; j <= k; j++) {
            for (int i = 0; i + (1ll << j) <= n; i++)
                table[j][i] = operation(table[j - 1][i], table[j - 1][i + (1ll << (j - 1))]);
        }
    }

    ll query(int l , int r) {
        int j = logs[r - l + 1];
        assert(r < n && l >= 0);
        ll answer = operation(table[j][l], table[j][r - (1ll << j) + 1]);
        return answer;
    }
};
class Solution {
public:
    long long countSubarrays(vector<int>&a, int k) {
        ll n = a.size();
        sparseTable sg;
        sg.init(n);
        sg.build(a);
        ll sa = 0;
        for (ll i = 0; i < n; i++) {
            ll ok = i, ng = n - 1, lo = -1;
            while (ok <= ng) {
                ll m = (ok + ng) / 2;
                if (sg.query(i, m) <= k) {
                    lo = m;
                    ng = m - 1;
                } else {
                    ok = m + 1;
                }
            }
            ok = i, ng = n - 1;
            ll hi = -1;
            while (ok <= ng) {
                ll m = (ok + ng) / 2;
                if (sg.query(i, m) >= k) {
                    hi = m;
                    ok = m + 1;
                } else {
                    ng = m - 1;
                }
            }
            ok = i, ng = n - 1;
            ll is = -1;
            while (ok <= ng) {
                ll m = (ok + ng) / 2;
                ll x = sg.query(i, m);
                if (x == k) {
                    is = 1;
                    break;
                }
                else if (x < k) {
                    ng = m - 1;
                } else {
                    ok = m + 1;
                }
            }
            if (is != -1) sa += hi - lo + 1;
        }
        return sa;
    }
};