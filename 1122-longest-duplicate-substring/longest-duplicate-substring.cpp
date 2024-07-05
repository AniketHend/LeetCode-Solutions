class Solution {
public:
    using ll = long long;

    struct Hash {
        const ll MOD = 1e9 + 7;
        const ll BASE1 = 5689;
        const ll BASE2 = 8861;
        vector<pair<ll, ll>> hashes, Pow;

        Hash(string s) {
            hashes.assign(s.size() + 1, {0, 0});
            Pow.assign(s.size() + 1, {1, 1});

            for (int i = 0; i < s.size(); i++) {

                hashes[i + 1] = {
                    (hashes[i].first * BASE1 + (s[i] - 'a' + 1)) % MOD,
                    (hashes[i].second * BASE2 + (s[i] - 'a' + 1)) % MOD};

                Pow[i + 1] = {(Pow[i].first * BASE1) % MOD,
                              (Pow[i].second * BASE2) % MOD};
            }
        }

        // INPUT IS 0 BASED INDEXING
        pair<ll, ll> get(int l, int r) {
            l++;
            r++;

            ll hash1 =
                (hashes[r].first -
                 (hashes[l - 1].first * Pow[r - l + 1].first) % MOD + MOD) %
                MOD;

            ll hash2 =
                (hashes[r].second -
                 (hashes[l - 1].second * Pow[r - l + 1].second) % MOD + MOD) %
                MOD;

            return {hash1, hash2};
        }
    };

    bool checkdup(string& s, int& mid, Hash& a) {
        map<pair<ll, ll>, int> mp;
        for (int i = 0; i < s.size() - mid + 1; i++) {
            pair<ll, ll> given = a.get(i, i + mid - 1);

            if (mp.find(given) == mp.end()) {
                mp[given]++;
            } else {
                return true;
            }
        }

        return false;
    }

    string longestDupSubstring(string s) {

        int n = s.size();
        int left = 0;
        int right = n;
        int ans = 0;

        Hash a(s);

        while (left <= right) {
            int mid = (left + right) / 2;

            if (checkdup(s, mid, a)) {
                left = mid + 1;
                ans = mid;
            } else {
                right = mid - 1;
            }
        }

        if (ans == 0) {
            return "";
        }

        map<pair<int, int>, int> mp;
        for (int i = 0; i < n - ans + 1; i++) {
            if (mp.find(a.get(i, i + ans - 1)) == mp.end()) {
                mp[a.get(i, i + ans - 1)]++;
            } else {
                return s.substr(i, ans);
            }
        }
        return "";
    }
};