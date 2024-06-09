class Solution {
public:
    int maxTotalReward(vector<int>& a) {
        const int N = 99999 + 1;
        bitset<N> dp;
        dp[0] = 1;
        bitset<N> ndp;

        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());

        int p = 0;
        for (auto& num : a) {
            while (p < num)
                ndp.set(p++);
            dp |= ((dp & ndp) << num);
        }
        int y = N - 1;
        while (!dp[y])
            y--;
        return y;
    }
};