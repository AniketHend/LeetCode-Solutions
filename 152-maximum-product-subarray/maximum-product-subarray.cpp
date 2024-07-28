using i128 = __int128;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        i128 prod1 = nums[0], prod2 = nums[0], result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            i128 temp = max(
                {(i128)nums[i], prod1 * (i128)1 * nums[i], prod2 * (i128)1 * nums[i]});
            prod2 = min(
                {(i128)1 * nums[i], prod1 * (i128)1 * nums[i], prod2 * (i128)1 * nums[i]});
            prod1 = temp;
            result = max(result, prod1);
        }

        return result;
    }
};