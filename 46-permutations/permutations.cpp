class Solution {
public:
    vector<vector<int>> permute(vector<int>& s) {
        vector<vector<int>> sa;
        sort(s.begin(), s.end());
        vector<int> v;
        int n = s.size();
        function<void(int)> f = [&](int msk) {
            if (__builtin_popcount(msk) == s.size()) {
                sa.push_back(v);
                return;
            }
            for (int i = 0; i < n; i++) {
                if (!(msk & (1 << i))) {
                    v.push_back(s[i]);
                    f(msk | (1 << i));
                    v.pop_back();
                }
            }
        };
        f(0);
        return sa;
    }
};