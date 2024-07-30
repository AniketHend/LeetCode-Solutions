static const int _ = []() {ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0;}();

class Solution {
public:
    int minimumDeletions(const string & s) const {
        int ans = INT_MAX;
        int pre[2] = {0, 0};
        int suf[2] = {0, 0};
        for (char ch : s)
            suf[ch - 'a']++;
        for (int i = 0; i < s.size(); i++) {
            // ithun b
            suf[s[i] - 'a']--;
            const int x = pre[1];
            const int y = suf[0];
            pre[s[i] - 'a']++;
            ans = min(ans, x + y);
        }
        return ans;
    }
};