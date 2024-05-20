class Solution {
public:
    long long rec(int i, int mask, int req_mask, vector<string>& req_skills,
                  vector<vector<string>>& people,
                  unordered_map<string, int>& mp,
                  vector<vector<long long>>& dp) {

        if (i == people.size()) {
            if (mask == req_mask) {
                return 0;
            }
            return INT_MAX;
        }

        if (dp[i][mask] != -1) {
            return dp[i][mask];
        }

        long long ans = INT_MAX;
        int new_mask = mask;
        for (auto skill : people[i]) {
            if (mp.count(skill)) {
                new_mask = new_mask | (1ll << mp[skill]);
            }
        }
        // cout<<i<<" "<<new_mask<<endl;
        if (new_mask != mask) {
            ans = min(ans, 1 + rec(i + 1, new_mask, req_mask, req_skills,
                                   people, mp, dp));
        }

        ans = min(ans, rec(i + 1, mask, req_mask, req_skills, people, mp, dp));

        return dp[i][mask] = ans;
    }
    void build(int i, int msk, int rqmsk, vector<int>& ans,
               vector<string>& req_skills, vector<vector<string>>& people,

               unordered_map<string, int>& mp, vector<vector<long long>>& dp) {
        if (i == people.size())
            return;

        int new_mask = msk;
        for (auto skill : people[i]) {
            if (mp.find(skill) != mp.end()) {
                new_mask = new_mask | (1ll << mp[skill]);
            }
        }

        long long ans1 = rec(i, msk, rqmsk, req_skills, people, mp, dp);
        long long ans_here =
            rec(i + 1, new_mask, rqmsk, req_skills, people, mp, dp);
        cout << i << " " << ans1 << " " << ans_here << endl;
        if (ans1 - 1 == ans_here) {
            ans.push_back(i);
            build(i + 1, new_mask, rqmsk, ans, req_skills, people, mp, dp);
        } else {
            build(i + 1, msk, rqmsk, ans, req_skills, people, mp, dp);
        }
    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills,
                                       vector<vector<string>>& people) {

        int pnum = people.size();
        int n = req_skills.size();
        vector<vector<long long>> dp(pnum + 1,
                                     vector<long long>(1ll << (n + 1), -1));
        int req_mask = (1 << n) - 1;
        unordered_map<string, int> mp;

        for (int i = 0; i < n; i++) {
            mp[req_skills[i]] = i;
        }

        vector<int> ans;
        int x = rec(0, 0, req_mask, req_skills, people, mp, dp);
        build(0, 0, req_mask, ans, req_skills, people, mp, dp);

        /*
        for (int i = 0; i < pnum + 1; i++) {
            for (int j = 0; j < pow(2, n + 1); j++) {
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }
        */
        cout << x << endl;
        return ans;
    }
};

// ["algorithms","math","java","reactjs","csharp","aws"]
// [["algorithms","math","java"],["algorithms","math","reactjs"],["java","csharp","aws"],["reactjs","csharp"],["csharp","math"],["aws","java"]]