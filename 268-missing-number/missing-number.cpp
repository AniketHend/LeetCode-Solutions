static const int _ = []() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        return (n * (n + 1)) / 2 - accumulate(nums.begin(), nums.end(), 0);
    }
};