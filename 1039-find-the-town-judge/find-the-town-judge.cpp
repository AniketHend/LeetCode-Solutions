class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> d(n), e(n);
        for (int i = 0; i < trust.size(); i++)
            d[trust[i][1] - 1]++, e[trust[i][0] - 1]++;

        for (int i = 0; i < n; i++)
            if (d[i] == n - 1 && e[i] == 0)
                return i + 1;
        return -1;
    }
};