class Solution {
public:
    bool canJump(vector<int>& nums) {
        int can = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (i > can)
                return false;
            can = max(can, i + nums[i]);
        }
        return true;
    }
};