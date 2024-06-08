class Solution {
public:
    bool checkSubarraySum(vector<int>& v, int k) {
        // sort(v.begin(), v.end());
        if (v.size() < 2)
            return false;
        if(k==1) return true;
        long long maxi = 0;
        long long sum = 0;
        for (int i = 0; i < v.size(); i++) {
            sum += v[i];
        }
        long long limit = sum / k + 1;
        bool ok = false;
        // for (auto& i : v) {
        //     if (i == 0)
        //         return true;
        // }
        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i] == v[i + 1] && v[i] == 0)
                return true;
        }
        for (long long i = k; i <= sum; i += k) {
            long long l = 0;
            long long tempsum = 0;
            for (int r = 0; r < v.size(); r++) {
                tempsum += v[r];
                while (tempsum > i) {
                    tempsum -= v[l];
                    l++;
                }
                if (r - l >= 1 && tempsum == i) {
                    return true;
                }
            }
            if (v.size() - 1 - l >= 1 && tempsum == i) {
                return true;
            }
        }
        return ok;
    }
};