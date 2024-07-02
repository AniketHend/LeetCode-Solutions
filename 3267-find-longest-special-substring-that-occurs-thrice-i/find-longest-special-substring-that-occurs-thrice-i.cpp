static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool check(string& s, int len) {
        vector<int> v(26, 0);
        vector<int> cur(26, 0);
        int n = s.size();
        for (int i = 0; i < len - 1; i++)
            cur[s[i] - 'a']++;
        for (int i = len - 1; i < n; i++) {
            cur[s[i] - 'a']++;
            if (i - len >= 0)
                cur[s[i - len] - 'a']--;
            if (cur[s[i] - 'a'] == len) {
                v[s[i] - 'a'] += 1;
            }
            if (v[s[i] - 'a'] >= 3) {
                return true;
            }
        }
        return false;
    }
    int maximumLength(string s) {
        int n = s.size();
        int l = 1, h = n;
        int ans = -1;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (check(s, mid)) {
                ans = mid;
                l = mid + 1;
            } else
                h = mid - 1;
        }
        return ans;
    }
};