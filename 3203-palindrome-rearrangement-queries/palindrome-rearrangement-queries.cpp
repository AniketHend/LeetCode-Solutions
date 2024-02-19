class CustomDS {
    int n;
    vector<int> is_match;
    vector<int> cntA[26];
    vector<int> cntB[26];
public:
    void init(string a, string b) {
        n = a.length();
        is_match.assign(n, 0);

        for (int i = 0; i < 26; i++) {
            cntA[i].assign(n, 0);
            cntB[i].assign(n, 0);
        }

        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) {
                is_match[i] = 1;
            }
            cntA[a[i] - 'a'][i] = 1;
            cntB[b[i] - 'a'][i] = 1;
        }

        for (int i = 1; i < n; i++) {
            is_match[i] += is_match[i - 1];

            for (int ch = 0; ch < 26; ch++) {
                cntA[ch][i] += cntA[ch][i - 1];
                cntB[ch][i] += cntB[ch][i - 1];
            }
        }

    }

    vector<int> freq(int l, int r, bool forA) {
        if (r < l) return {};
        vector<int> rs(26, 0);
        for (int ch = 0; ch < 26; ch++) {
            if (forA) rs[ch] = cntA[ch][r] - (l > 0 ? cntA[ch][l - 1] : 0);
            else rs[ch] = cntB[ch][r] - (l > 0 ? cntB[ch][l - 1] : 0);
        }
        return rs;
    }

    // exactly same
    bool is_same(int l, int r) {
        if (r < l) return true;
        int m = is_match[r] - (l > 0 ? is_match[l - 1] : 0);
        // cout << m << " " << (r - l + 1) << endl;
        return (m == (r - l + 1));
    }

    // same after rearrangement
    bool is_same_rearrange(int l, int r) {
        if (r < l) return true;

        for (int ch = 0; ch < 26; ch++) {
            int acnt = cntA[ch][r] - (l > 0 ? cntA[ch][l - 1] : 0);
            int bcnt = cntB[ch][r] - (l > 0 ? cntB[ch][l - 1] : 0);
            if (acnt != bcnt) {
                return false;
            }
        }
        return true;
    }

    //
    bool query(int l, int r) {
        return (is_same(0, l - 1) && is_same_rearrange(l, r) && is_same(r + 1, n - 1));
    }

    bool query(int a, int b, int c, int d) {
        /*  partial overlap */
        if ( (b >= c && b < d && a < c) || (a > c && a <= d && b > d) ) {
            if ((b >= c && b < d)) {
                auto oa = freq(a, c - 1, false);
                auto ob = freq(b + 1, d, true);
                auto ma = freq(a, b, true);
                auto mb = freq(c, d, false);

                for (int ch = 0; ch < 26; ch++) {
                    if (ma[ch] < oa[ch]) return false;
                    if (mb[ch] < ob[ch]) return false;
                    ma[ch] -= oa[ch];
                    mb[ch] -= ob[ch];
                }
                return is_same(0, a - 1) && ma == mb && is_same(d + 1, n - 1);
            }
            else {
                auto oa = freq(c, a - 1, true);
                auto ob = freq(d + 1, b, false);
                auto ma = freq(a, b, true);
                auto mb = freq(c, d, false);
                // for(auto i:oa) cout<<i<<" ";cout<<endl;
                // for(auto i:ob) cout<<i<<" ";cout<<endl;
                // for(auto i:ma) cout<<i<<" ";cout<<endl;
                // for(auto i:mb) cout<<i<<" ";cout<<endl;
                for (int ch = 0; ch < 26; ch++) {
                    if (ma[ch] < ob[ch]) return false;
                    if (mb[ch] < oa[ch]) return false;
                    ma[ch] -= ob[ch];
                    mb[ch] -= oa[ch];
                }
                return is_same(0, c - 1) && ma == mb && is_same(b + 1, n - 1);
            }
        }
        // full overlap
        else if ((a <= c && b >= d) || (c <= a && d >= b)) {
            // cout << a << " " << b << " " << c << ' ' << d << endl;
            int x = min(a, c);
            int y = max(b, d);
            // cout << x << " " << y << endl;
            return (is_same(0, x - 1) && query(x, y) && is_same(y + 1, n - 1));
        }
        else {
            if (a < c) {
                swap(a, c);
                swap(b, d);
            }
            return (is_same(0, c - 1) && is_same_rearrange(c, d) && is_same(d + 1, a - 1) && is_same_rearrange(a, b) && is_same(b + 1, n - 1));
        }
    }
};


class Solution {
public:
    vector<bool> canMakePalindromeQueries(string s, vector<vector<int>>Q) {
        int n = s.size();
        vector<array<int, 4>>q;
        for (int i = 0; i < Q.size(); i++) {
            array<int, 4>st;
            for (int j = 0; j < 4; j++) {
                st[j] = Q[i][j];
            }
            q.push_back(st);
        }
        string x = "", y = "";
        for (int i = 0; i < n; i++) {
            if (i < n / 2) x.push_back(s[i]);
            else y.push_back(s[i]);
        }
        reverse(y.begin(), y.end());
        CustomDS t;
        // cout << x << " " << y << endl;
        t.init(x, y);
        vector<bool> rs;
        for (auto i : q) {
            int a = i[0], b = i[1], c = i[2], d = i[3];
            rs.push_back(t.query(a, b, n - d - 1, n - c - 1));
        }
        return rs;
    }
};