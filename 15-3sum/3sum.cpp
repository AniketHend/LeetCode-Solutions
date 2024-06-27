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
        for (int i = 0; i < a.size() - 2; i++) {
            if (i > 0 && a[i] == a[i-1]) continue;
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