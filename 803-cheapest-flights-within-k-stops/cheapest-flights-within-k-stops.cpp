// dp[i][j] denotes the minimum cost to reach i from src using less than or
// equal to j stpes

// dp[i][j] = min(dp[i][j-1],X) X = dp[node][j-1] + w(node,i);

// dp[i][j] = 1e9
// dp[scr][0]=0;
#define ll long long
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<ll> dist(n, 1e12);
        vector<ll> next(n);
        dist[src] = 0;

        for (int i = 1; i <= k + 1; i++) {
            next = dist;
            for (auto it : flights) {
                ll from = it[0];
                ll to = it[1];
                ll w = it[2];
                next[to] = min(next[to], dist[from] + w);
            }

            // for (int i = 0; i < n; i++)
            //     cout << next[i] << " ";
            // cout << endl;

            dist = next;
        }
        // for (int i = 0; i < n; i++)
        //     cout << next[i] << " ";
        // cout << endl;
        if (dist[dst] == 1e12) {
            return -1;
        }
        return dist[dst];
    }
};