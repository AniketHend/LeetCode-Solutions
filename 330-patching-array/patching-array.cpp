static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        sort(nums.begin(), nums.end());
        long long sa = 1;
        int y = 0;
        for (auto& num : nums) {
            while (num > sa && sa <= n) {
                y += 1;
                sa += sa;
            }
            sa += num;
        }
        while (sa <= n) {
            y++;
            sa += sa;
        }
        return y;
    }
};