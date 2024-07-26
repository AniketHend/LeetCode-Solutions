static const int _ = []() {ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0;}();

// solution
class Solution {
public:
  int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    int dp[n][n];
    for (int start = 0; start < n; ++start) {
      dp[start][start] = 0;
      for(int end=0;end<n;++end) {
        if(start != end) dp[start][end] = 1e9;
      }
    }

    for (auto &e : edges) {
      dp[e[0]][e[1]] = e[2];
      dp[e[1]][e[0]] = e[2];
    }

    for (int mid = 0; mid < n; ++mid) {
      for (int start = 0; start < n; ++start) {
        for (int end = 0; end < n; ++end) {
          dp[start][end] = min(dp[start][end],dp[start][mid]+dp[mid][end]);
        }
      }
    }
    int sa = 1e9, ind;
    for (int node = 0; node < n; node++) {
      int now = 0;
      for (int j = 0; j < n; j++) {
        now += (dp[node][j] <= distanceThreshold);
      }
      if (sa >= now) sa = now, ind = node;
    }
    return ind;
  }
};
