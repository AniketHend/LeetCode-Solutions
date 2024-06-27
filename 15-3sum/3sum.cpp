static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> threeSum(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> ans;
        sort(a.begin(), a.end());
        if (a[0] == a[n - 1] && a[0] == 0) {
            return {{0, 0, 0}};
        } else if (a[0] == a[n - 1]) {
            return {};
        }
        for (int i = 0; i < a.size() - 2; i++) {
            int j = i + 1, k = a.size() - 1;
            while (j < k) {
                int csum = a[i] + a[j] + a[k];
                if (csum == 0)
                    ans.push_back({a[i], a[j], a[k]});
                if (csum <= 0)
                    j++;
                else
                    k--;
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};