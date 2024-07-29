// solution
class Solution {
public:
  int longestPath(vector<int>& parent, string s) {
    int n = parent.size();
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; ++i) {
      adj[parent[i]].push_back(i);
    }
    int ans = 0;
    auto dnc = [&](auto && dnc, int u)->array<int, 2> {
      array<int, 2> now = {1, 1};
      vector<int> sa;
      for (auto v : adj[u]) {
        auto child = dnc(dnc, v);
        if (s[v] != s[u]) {
          sa.push_back(child[0]);
        }
        now[1] = max(child[1], now[1]);
      }
      sort(sa.rbegin(), sa.rend());
      if (sa.size()) {
        now[0] += sa[0];
        now[1] = max(now[1], sa[0] + 1);
        if (sa.size() > 1) {
          now[1] = max(now[1], sa[0] + 1 + sa[1]);
        }
      }
      
      return now;
    };

    auto ch = dnc(dnc, 0);
    return ch[1];
  }
};
