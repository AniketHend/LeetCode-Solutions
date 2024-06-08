
#define ll long long
const ll mod = 1e9 + 7;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<ll, ll>> g[n + 1];
        for (auto it : roads) {
            g[it[0]].push_back({it[1], it[2]});
            g[it[1]].push_back({it[0], it[2]});
        }
        set<pair<ll, ll>> st;
        st.insert({0, 0});
        vector<ll> dist(n, 1e12);
        dist[0] = 0;
        vector<ll> nosWays(n, 0);
        nosWays[0] = 1;
        while (!st.empty()) {
            pair<ll, ll> p = *st.begin();
            st.erase(p);
            ll dist_p = p.first;
            ll node = p.second;
            // if(dist_p > dist[node]) continue;
            for (auto c : g[node]) {
                ll to = c.first;
                ll w = c.second;
                if (dist_p + w < dist[to]) {
                    st.erase({dist[to], to});
                    nosWays[to] = nosWays[node];
                    dist[to] = dist_p + w;
                    st.insert({dist[to], to});
                } else if (dist_p + w == dist[to]) {
                    nosWays[to] = (nosWays[node] + nosWays[to]) % mod;
                }
            }
        }
        cout << dist[n - 1] << endl;
        return (int)nosWays[n - 1];
    }
};