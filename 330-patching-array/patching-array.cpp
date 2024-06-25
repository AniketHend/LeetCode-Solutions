
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        sort(nums.begin(), nums.end());
        long long sa = 1;
        int y = 0;
        for (auto& num : nums) {
            while (num > sa && sa <= n) {
                // cout << num << " " << sa << endl;
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