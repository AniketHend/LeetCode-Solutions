
class Solution {
public:
    int minimumSize(vector<int>& nums, int m) {
        auto chk = [&](int k) {
            int ops = m;
            for (int i : nums) {
                int rq = max(0, (i + k - 1) / k - 1);
                ops -= rq;
            }
            return ops >= 0;
        };

        int ok = 1, ng = 1e9;
        while (ok < ng) {
            int mid = (ok + ng) / 2;
            chk(mid) ? ng = mid : ok = mid + 1;
        }
        return ok;
    }
};