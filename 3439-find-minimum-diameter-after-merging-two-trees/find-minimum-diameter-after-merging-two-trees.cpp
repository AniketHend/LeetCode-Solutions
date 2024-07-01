#define INF INT_MAX
struct centroid {
    int N;
    vector<int> dist;
    vector<vector<int>> adj;
    int v, w;
    int diameter;
    centroid(const int& N) : N(N), dist(N, INF), adj(N), v(0), diameter(0) {}

    void add_edge(int u, int v) {
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    pair<int, int> bfs(int root, vector<int>& dist) {
        int v = root;
        int ma = 0;
        queue<tuple<int, int, int>> q;
        q.emplace(0, root, -1);
        while (!q.empty()) {
            auto x = q.front();
            q.pop();
            int d = get<0>(x);
            int cur = get<1>(x);
            int par = get<2>(x);
            dist[cur] = d;
            if (dist[cur] > ma) {
                ma = dist[cur];
                v = cur;
            }
            for (int nv : adj[cur]) {
                if (nv == par) {
                    continue;
                }
                q.emplace(d + 1, nv, cur);
            }
        }
        return make_pair(ma, v);
    }

    void build(int root) {
        dist.assign(N, INF);
        pair<int, int> p = bfs(root, dist);
        w = p.second;
        dist.assign(N, INF);
        pair<int, int> res = bfs(p.second, dist);
        diameter = res.first;
        v = res.second;
    }

    vector<int> get_center(int root) {
        vector<int> res;
        vector<int> dist_v(N, INF);
        vector<int> dist_w(N, INF);
        auto res_v = bfs(v, dist_v);
        auto res_w = bfs(w, dist_w);
        for (int i = 0; i < N; i++) {
            if (dist_v[i] == diameter / 2 and
                dist_w[i] == diameter - diameter / 2) {
                res.emplace_back(i);
            }
        }
        return res;
    }
};

class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& e1,
                                  vector<vector<int>>& e2) {

        int N1 = e1.size() + 1;
        int N2 = e2.size() + 1;

        centroid c1(N1), c2(N2);

        for (auto e : e1) {
            c1.add_edge(e[0], e[1]);
        }
        for (auto e : e2) {
            c2.add_edge(e[0], e[1]);
        }
        c1.build(0);
        c2.build(0);
        int x = c1.get_center(0)[0];
        int y = c2.get_center(0)[0];
        centroid c3(N1 + N2);
        for (auto e : e1) {
            c3.add_edge(e[0], e[1]);
        }
        for (auto e : e2) {
            c3.add_edge(e[0] + N1, e[1] + N1);
        }
        c3.add_edge(x, y + N1);
        c3.build(0);
        return c3.diameter;
    }
};