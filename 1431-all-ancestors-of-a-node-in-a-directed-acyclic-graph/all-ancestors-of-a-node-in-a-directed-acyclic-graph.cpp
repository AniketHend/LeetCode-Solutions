
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> q, in(n);
        vector<set<int>> sa(n), g(n);

        for (auto e : edges) {
            g[e[0]].insert(e[1]);
            in[e[1]]++;
        }

        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                q.push_back(i);
            }
        }
        for (int i = 0; i < q.size(); ++i) {
            int u = q[i];
            for (auto v : g[u]) {
                in[v]--;
                if (!in[v])
                    q.push_back(v);
            }
        }

        for (int i = 0; i < q.size(); ++i) {
            for (auto v : g[q[i]]) {
                for(auto it:sa[q[i]]) sa[v].insert(it);
                // sa[v].insert(sa[v].end(), sa[q[i]].begin(), sa[q[i]].end());
                sa[v].insert(q[i]);
            }

        }

        vector<vector<int>> saa(n);
        for(int i=0;i<n;i++) {
            for(auto it:sa[i]) saa[i].push_back(it);
            // saa[i].insert(sa[i].end(), sa[i].begin(), sa[i].end());
        }
        return saa;
    }
}; 