// solution
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int N = nums.size();

        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        int n = nums.size();
        int op = N - 1;
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < i && nums[j] < nums[i] - (N - 1)) {
                j++;
            }
            op = min(op, N - (i - j + 1));
            // cout << j << " " << i << " " << N - (i - j + 1) << endl;
        }
        return op;
    }
};
