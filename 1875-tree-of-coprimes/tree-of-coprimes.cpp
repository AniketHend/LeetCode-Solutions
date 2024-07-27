static const int _ = []() {ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0;}();


// solution
class Solution {
public:
  vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
    int n = nums.size();
    vector<vector<int>> a(n);
    for (int i = 1; i < n; i++) {
      int u = edges[i - 1][0], v = edges[i - 1][1];
      a[u].push_back(v);
      a[v].push_back(u);
    }

    vector<pair<int, int>> dp(51, { -1, -1});
    vector<int> sa(n);
    auto dfs = [&](auto && dfs, int u, int p)->void {
      int dis = INT_MAX, node = -1;
      auto ndp = dp;

      for (int j = 1; j <= 50; j++) {
        if (dp[j].first != -1 && __gcd(j, nums[u]) == 1) {
          if (dis > dp[j].second) {
            dis = dp[j].second;
            node = dp[j].first;
          }
        }
        if (dp[j].second != -1) {
          dp[j].second++;
        }
      }
      dp[nums[u]].first = u;
      dp[nums[u]].second = 1;
      sa[u] = node;

      for (auto &v : a[u]) {
        if (v == p) continue;
        dfs(dfs, v, u);
      }
      dp = ndp;
    };
    dfs(dfs, 0, -1);
    return sa;
  }
};