class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int K) {
        vector<vector<pair<int, int>>> g(n + 1);
        for (auto i : flights) {
            g[i[0]].push_back({i[1], i[2]});
        }

        queue<pair<int, pair<int, int>>> q;
        vector<int> dis(n + 1, INT_MAX);
        dis[src] = 0;
        q.push({0, {src, 0}});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int stop = it.first;
            if (stop > K)
                continue;
            int node = it.second.first;
            int distance = it.second.second;
            for (auto k : g[node]) {
                int newn = k.first;
                int costnew = k.second;
                if (dis[newn] > (distance + costnew) and stop <= K) {
                    dis[newn] = distance + costnew;
                    q.push({stop + 1, {newn, distance + costnew}});
                }
            }
        }
        if (dis[dst] == INT_MAX)
            return -1;
        else
            return dis[dst];
    }
};