class Solution {
public:
    int minval(vector<int>& bloomDay, int n) {
        int mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            mini = min(mini, bloomDay[i]);
        }
        return mini;
    }
    int maxval(vector<int>& bloomDay, int n) {
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, bloomDay[i]);
        }
        return maxi;
    }
    bool check(vector<int>& bloomDay, int n, int day, int m, int k) {
        int cnt = 0;
        int num = 0;
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= day)
                cnt++;
            else {
                num += cnt / k;
                cnt = 0;
            }
        }
        num += cnt / k;
        if (num >= m)
            return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (n < m *1ll* k)
            return -1;
        int low = minval(bloomDay, n);
        int high = maxval(bloomDay, n);
        int ans;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            bool val = check(bloomDay, n, mid, m, k);
            if (val == true) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }
};