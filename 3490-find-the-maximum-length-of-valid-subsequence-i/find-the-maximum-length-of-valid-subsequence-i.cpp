class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int ans = 0;
        int k = 2;
        for (int i = 0; i < k; ++i) {
            vector<int> arr(k);
            for (int j = 0; j < nums.size(); j++) {
                int x = nums[j] % k;
                int y = (i - x + k) % k;
                arr[x] = max(arr[x], arr[y] + 1);
                ans = max(ans, arr[x]);
            }
        }
        return ans;
    }
};