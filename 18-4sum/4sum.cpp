static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
vector<vector<long long>> threeSum(int j, vector<int>& a, int T) {
    #define int long long 
    vector<vector<int>> ans;
    for (int i = j; i < a.size() - 2; i++) {
        if (i > j && a[i] == a[i - 1])
            continue;
        int j = i + 1, k = a.size() - 1;
        while (j < k) {
            long long csum = a[i]*1ll + a[j]*1ll + a[k]*1ll;
            if (csum == T)
                ans.push_back({a[i], a[j], a[k]});
            if (csum <= T)
                j++;
            else
                k--;
        }
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    #undef int
    return ans;
}

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i + 3 < n; i++) {
            auto it = threeSum(i + 1, nums, target - nums[i]);
            for (auto q : it) {
                ans.push_back({nums[i], (int)q[0], (int)q[1], (int)q[2]});
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};