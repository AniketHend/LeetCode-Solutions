#define ll long long
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<ll, ll>> adj[n];
        for (auto x : roads) {
            int from = x[0];
            int to = x[1];
            int weight = x[2];
            adj[from].push_back({to, weight});
            adj[to].push_back({from, weight});
        }
        set<pair<ll, pair<ll, ll>>> st;
        //{distance , ways}
        vector<pair<ll, ll>> dist(n, {1e15, 0});
        dist[0] = {0, 1};
        // format of storing -> {distance , {node, current number of ways}}
        st.insert({0, {0, 1}});

        while (st.size()) {
            auto it = *st.begin();
            st.erase(it);

            ll cur_dis = it.first;
            ll cur_node = it.second.first;
            ll ways = it.second.second;
            if(cur_dis > dist[cur_node].first) continue;
            for (auto x : adj[cur_node]) {
                ll child = x.first;
                ll weight = x.second;

                if (dist[child].first > cur_dis + weight) {
                    st.erase({dist[child].first, {child, dist[child].second}});
                    dist[child] = {cur_dis + weight, dist[cur_node].second};
                    st.insert({dist[child].first, {child, dist[child].second}});
                } else if (dist[child].first == cur_dis + weight) {
                    dist[child].second =
                        (dist[child].second + dist[cur_node].second) % 1000000007;
                }
            }
        }
        return dist[n - 1].second;
    }
};