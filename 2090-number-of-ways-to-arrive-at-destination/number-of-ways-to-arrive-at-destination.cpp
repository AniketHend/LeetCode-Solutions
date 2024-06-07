class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long, long long>>> adj(n);
        for (int i = 0; i < roads.size(); i++) {
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        priority_queue<pair<long long, long long>,
                       vector<pair<long long, long long>>,
                       greater<pair<long long, long long>>>
            pq;
        vector<long long> dist(n, LONG_MAX);
        vector<long long> ways(n, 0);
        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;
        int mod = 1000000007;
        while (!pq.empty()) {
            long long node = pq.top().second;
            long long distance = pq.top().first;
            pq.pop();
            if (distance > dist[node])
                continue;
            for (auto& it : adj[node]) {
                long long adjnode = it.first;
                long long edgewt = it.second;
                if (distance + edgewt < dist[adjnode]) {
                    dist[adjnode] = dist[node] + edgewt;
                    ways[adjnode] = ways[node];
                    pq.push({dist[adjnode], adjnode});
                } else if (dist[node] + edgewt == dist[adjnode]) {
                    ways[adjnode] += ways[node];
                    ways[adjnode] %= mod;
                }
            }
        }
        return (ways[n - 1]) % mod;
    }
};
