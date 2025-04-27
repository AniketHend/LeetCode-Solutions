class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int x = 0;
        for (int i = 1; i + 1 < nums.size(); i++) {
            if (nums[i] & 1)
                continue;
            if ((nums[i - 1] + nums[i + 1]) == nums[i] / 2)
                x++;
        }
        return x;
    }
};