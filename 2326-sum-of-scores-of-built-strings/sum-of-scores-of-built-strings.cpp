class Solution {
public:
#define ll long long int
    static const ll M = 1e9 + 7;
    static const ll BASE1 = 5689, BASE2 = 8861;

    struct Hash {
        vector<pair<ll, ll>> hashes, po;
        Hash(string s) {
            hashes.assign(s.size() + 1, {1, 1});
            po.assign(s.size() + 1, {1, 1});
            for (ll i = 0; i < (ll)(s.size()); i++) {
                hashes[i + 1] = {
                    (hashes[i].first * BASE1 + ((s[i] - 'a') + 1)) % M,
                    (hashes[i].second * BASE2 + ((s[i] - 'a') + 1)) % M};
                po[i + 1] = {(po[i].first * BASE1) % M,
                             (po[i].second * BASE2) % M};
            }
        }

        pair<ll, ll> g(ll l, ll r) {
            l++, r++;
            ll hash1 = (hashes[r].first -
                        (hashes[l - 1].first * po[r - l + 1].first) % M + M) %
                       M;
            ll hash2 = (hashes[r].second -
                        (hashes[l - 1].second * po[r - l + 1].second) % M + M) %
                       M;
            return {hash1, hash2};
        }
    };

    long long sumScores(string s) {
        struct Hash h = Hash(s);
        ll n = s.size();
        ll ans = 0;

        for (ll i = n - 1; i >= 0; i--) {
            ll lcp = 0;
            ll left = i;
            ll right = n - 1;
            while (left <= right) {
                ll mid = left + (right - left) / 2;
                ll len = mid - i + 1;
                if (h.g(0, len - 1) == h.g(i, mid)) {
                    lcp = len;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            ans += lcp;
        }
        return ans;
    }
};