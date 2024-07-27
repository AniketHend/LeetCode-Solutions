#define ll long long
#define INF 1e18
#define ff first
#define ss second
static const int _ = []() {ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0;}();

class Solution {

    void FloydWarshall(int n, vector<vector<pair<int, ll>>> adj,
                       vector<vector<ll>>& dist) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = INF;
            }
            dist[i][i] = 0;
        }
        for (int i = 0; i < n; i++) {
            for (auto j : adj[i]) {
                dist[i][j.ff] = min(dist[i][j.ff], j.ss);
            }
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] < INF &&
                        dist[k][j] <
                            INF) // for updating only when there is a path
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

public:
    long long minimumCost(string S, string T, vector<char>& o, vector<char>& c,
                          vector<int>& cost) {
        vector<vector<pair<int, ll>>> adj(26);

        for (int i = 0; i < o.size(); i++) {
            int x = o[i] - 'a';
            int y = c[i] - 'a';
            adj[x].push_back({y, cost[i] * 1ll});
        }
        vector<vector<ll>> dis(26, vector<ll>(26));
        FloydWarshall(26, adj, dis);

        long long res = 0ll;
        for (int i = 0; i < S.size(); i++) {
            int x = S[i] - 'a';
            int y = T[i] - 'a';
            if (x != y) {
                if (dis[x][y] == INF)
                    return -1;
                res += dis[x][y];
            }
        }
        return res;
    }
};