class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        map<long long, pair<long long,long long>> m, p;
        for (int i = 0; i < n; i++) {
            m[arr[i]].first++;
            m[arr[i]].second += i;
        }
        vector<long long> rs;
        for (int i = 0; i < n; i++) {
            m[arr[i]].first--;
            m[arr[i]].second -= i;
            rs.push_back(p[arr[i]].first * 1ll * i - p[arr[i]].second +
                         m[arr[i]].second - m[arr[i]].first * 1ll * i);
            p[arr[i]].first++;
            p[arr[i]].second += i;
        }
        return rs;
    }
};