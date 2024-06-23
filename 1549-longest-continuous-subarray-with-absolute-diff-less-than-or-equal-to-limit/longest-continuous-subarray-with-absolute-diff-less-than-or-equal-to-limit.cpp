class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        int i = 0;
        int j = 0;
        deque<int> maxi;
        deque<int> mini;
        int ans = 0;
        int n = nums.size();
        while (j < n) {
            while (!maxi.empty() && maxi.back() < nums[j]) {
                maxi.pop_back();
            }
            while (!mini.empty() && mini.back() > nums[j]) {
                mini.pop_back();
            }
            maxi.push_back(nums[j]);
            mini.push_back(nums[j]);

            while (maxi.front() - mini.front() > limit) {
                if (maxi.front() == nums[i])
                    maxi.pop_front();
                if (mini.front() == nums[i]) {
                    mini.pop_front();
                }
                i++;
            }
            if (maxi.front() - mini.front() <= limit) {
                ans = max(ans, j - i + 1);
                j++;
            }
        }
        return ans;
    }
};