class Solution {
public:
    vector<int> vis;

    void dfs(int source, int parent, vector<vector<int>>& a) {
        vis[source] = 1;
        for (auto& it : a[source]) {
            if (vis[it] == 0) {
                dfs(it, source, a);
            }
        }
    }

    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vis.assign(n, 0);
        vector<vector<int>> adj(n), check(n);

        for (auto& i : invocations) {
            int u = i[0];
            int v = i[1];
            check[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(k, -1, check);

        for (auto& i : invocations) {
            if (!vis[i[0]] && vis[i[1]]) {
                vis.assign(n,0); break;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};