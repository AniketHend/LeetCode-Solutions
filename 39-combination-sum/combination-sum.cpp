class Solution {
public:
    void solve(vector<int> &candidates, int index, int sum, int target,
               vector<int> support, vector<vector<int>>& ans) {
        if (sum == target) {
            ans.push_back(support);
            return;
        }
        if (sum > target) {
            return;
        }
        if (index >= candidates.size()) {
            return;
        }
        support.push_back(candidates[index]);
        solve(candidates, index, sum + candidates[index], target, support, ans);
        support.pop_back();
        solve(candidates, index + 1, sum, target, support, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> support;
        solve(candidates, 0, 0, target, support, ans);
        return ans;
    }
};