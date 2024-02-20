struct DSU {
    vector<int> par, rnk, sz;
    int c;
    DSU(int n) : par(n + 1), rnk(n + 1, 0), sz(n + 1, 1), c(n) {
        for (int i = 1; i <= n; ++i) {
            par[i] = i;
        }
    }
    int find(int i) { return (par[i] == i ? i : (par[i] = find(par[i]))); }
    bool same(int i, int j) { return find(i) == find(j); }
    int get_size(int i) { return sz[find(i)]; }
    int count() {
        return c; // connected components
    }
    int merge(int i, int j) {
        if ((i = find(i)) == (j = find(j)))
            return -1;
        else {
            --c;
        }
        if (rnk[i] > rnk[j]) {
            swap(i, j);
        }
        par[i] = j;
        sz[j] += sz[i];
        if (rnk[i] == rnk[j]) {
            rnk[j]++;
        }
        return j;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& e) {
        int n = e.size();
        DSU d = DSU(n + 1);
        vector<int> res;
        for (auto i : e) {
            int x = d.merge(i[0], i[1]);
            if (x == -1) {
                res = {i[0], i[1]};
            }
        }
        return res;
    }
};