class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int c = 0;
        int sa = 0;
        int n = nums.size();
        m[0] = 1;
        for (int i = 0; i < n; i++) {
            c += nums[i];
            if (m.find(c - k) != m.end())
                sa += m[c - k];
            m[c]++;
        }
        return sa;
    }
};