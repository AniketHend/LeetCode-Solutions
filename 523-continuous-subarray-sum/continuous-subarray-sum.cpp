class Solution {
public:
    bool checkSubarraySum(vector<int>& v, int k) {
        long long maxi = 0;
        long long sum = 0;
        for (int i = 0; i < v.size(); i++) {
            sum += v[i];
        }

        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i] == v[i + 1] && v[i] == 0)
                return true;
        }

        if (k == 1 && v.size() > 1) {
            return true;
        }
        if (v.size() < 2) {
            return false;
        }

        long long limit = sum / k + 1;
        bool ok = false;

        for (int i = k; i <= sum; i += k) {
            long long l = 0;
            int tempsum = v[0];
            for (int r = 1; r < v.size(); r++) {
                tempsum += v[r];
                while (tempsum > i) {
                    tempsum -= v[l];
                    l++;
                }
                if ((tempsum == i && r - l >= 1) ||
                    (tempsum == 0 && r - l >= 1)) {
                    ok = true;
                    break;
                }
            }
            if(ok) break;
        }
        return ok;
    }
};
