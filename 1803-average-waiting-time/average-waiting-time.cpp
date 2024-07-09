class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& cust) {
        int c = 0;
        double wait = 0;
        int n = cust.size();
        for (int i = 0; i < n; ++i) {
            if (c > cust[i][0]) {
                wait += c - cust[i][0];
            }
            wait += (cust[i][1]);
            c = max(c + cust[i][1], cust[i][0] + cust[i][1]);
        }
        wait /= n;
        return wait;
    }
};
