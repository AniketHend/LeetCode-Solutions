class Solution {
public:
    int solve(map<pair<int, int>, int>& mp, vector<int>& fib, int k, int i) {
        if (k == 0) {
            return 0;
        }

        if (k < 0) {
            return 1e9;
        }

        if (i == fib.size()) {
            return 1e9;
        }

        if (mp.find({i, k}) != mp.end()) {
            return mp[{i, k}];
        }

        int pick = 1e9;
        if (k - fib[i] >= 0)
            pick = 1 + solve(mp, fib, k - fib[i], i);
        int no_pick = solve(mp, fib, k, i + 1);

        return mp[{i, k}] = min(pick, no_pick);
    }
    int findMinFibonacciNumbers(int k) {
        vector<int> fib = {1, 1};
        int i = 2;
        while (fib.back() < k) {
            fib.push_back(fib[i - 1] + fib[i - 2]);
            i++;
        }

        int y = 0;
        while (k) {
            auto it = upper_bound(fib.begin(), fib.end(), k) - fib.begin();
            it--;
            y++;
            k -= fib[it];
        }
        return y;
    }
};