class Solution {
public:
    int minJumps(vector<int>& arr) {
        map<int, vector<int>> mpp;
        for (int i = 0; i < arr.size(); i++)
            mpp[arr[i]].push_back(i);
        for (auto [x, y] : mpp) {
            cout << x << "\n";
            for (int j : y)
                cout << j << " ";
            cout << endl;
        }
        int N = arr.size();
        map<int, vector<int>> g;
        vector<vector<int>> adj(N);
        for (int i = 0; i < (int)arr.size() - 1; i++) {
            int x = i;
            int y = i + 1;
            if (x != y) {
                adj[x].push_back(y);
                adj[y].push_back(x);
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            g[arr[i]].push_back(i);
            if (g[arr[i]].size() > 1) {
                int x = g[arr[i]][0];
                adj[x].push_back(i);
                adj[i].push_back(x);
            }
        }
        // for(int i=0;i<N;i++) cout << arr[i]<<" ";cout << endl;
        // for (int i = 0; i < N; i++) {
        //     for (int j : adj[i]) {
        //         cout << i << " " << j << endl;
        //     }
        // }
        int n = arr.size();
        vector<int> dp(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, 0});
        dp[0] = 0;
        vector<int> par(n, -1);
        map<int, int> got;
        while (!pq.empty()) {
            auto [y, x] = pq.top();
            pq.pop();
            if (y != dp[x])
                continue;
            if (!got[arr[x]]) {
                got[arr[x]] = 1;
                for (auto v : mpp[arr[x]]) {
                    if (dp[v] > dp[x] + 1) {
                        dp[v] = dp[x] + 1;
                        par[v] = x;
                        pq.push({dp[v], v});
                    }
                }
                pq.push({dp[x],x});
            } else {
                for (auto v : adj[x]) {
                    if (dp[v] > dp[x] + 1) {
                        dp[v] = dp[x] + 1;
                        par[v] = x;
                        pq.push({dp[v], v});
                    }
                }
            }
        }
        int cr = n - 1;
        while (cr >= 0) {
            cout << cr << " ";
            cr = par[cr];
        }
        return dp[n - 1];
    }
};
