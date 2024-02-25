const int mx = 100005 + 5;
static const int _ = []() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();

class Solution {
    bool prime[mx + 10];
    int pf[mx + 10];
    bool ok = false;
    void sieve(int n = mx) {
        ok = true;
        for (int i = 0; i < n + 10; i++) prime[i] = 1;
        prime[1] = prime[0] = 0;
        for (long long p = 2; p  < n; p++) {
            if (prime[p] == true) {
                pf[p] = p;
                for (long long i = p *1ll* p; i < n; i += p) {
                    prime[i] = false;
                    pf[i] = p;
                }
            }
        }
    }

    struct dsu {
        vector<int> parent;
        dsu(int m) {parent.resize(m + 1); for (int i = 0; i <= m; ++i) {parent[i] = i;}}
        int get(int a) {if (a == parent[a]) {return a;} return parent[a] = get(parent[a]);}
        void unite(int a, int b) {parent[get(a)] = get(b);}
    };
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        dsu d(n);
        if (!ok) sieve();
        map<int, set<int>>mp;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            while (x > 1) {
                mp[pf[x]].insert(i);
                x /= pf[x];
            }
        }
        for (auto i : mp) {
            vector<int> v;
            for (auto it : i.second) v.push_back(it);
            for (int u = 0; u < v.size() - 1; u++) {
                d.unite(v[u], v[u + 1]);
            }
        }
        set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(d.get(i));
        }
        return st.size() == 1;
    }
};