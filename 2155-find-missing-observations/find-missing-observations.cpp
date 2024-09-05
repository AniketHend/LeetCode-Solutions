class Solution {
public:
    vector<int> missingRolls(vector<int>& a, int mean, int n) {
        int m = a.size();
        int sum = accumulate(a.begin(), a.end(), 0);
        int need = mean * (n + m) - sum;
        // cout << need << endl;
        if (need > 6 * n || need < n) {
            return {};
        }
        vector<int> rq(n);
        int now = n;
        while (need && now) {
            int can = need / now;
            // cout << can <<" " << n/ow << endl;
            if (can) {
                rq[0] += can;
                if (now < n) {
                    rq[now] -= can;
                }
            }
            need -= can * now;
            now--;
        }
        for (int i = 1; i < n; i++)
            rq[i] += rq[i - 1];
        return rq;
    }
};