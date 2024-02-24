#include <bits/stdc++.h>
using namespace std;

static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#ifdef ONLINE_JUDGE
#include "./debug.h"
#define dbg(...)                                                               \
    cerr << __LINE__ << " :: ", _DEBUG_UTIL_::printer(#__VA_ARGS__, __VA_ARGS__)
#define dbgA(arr, n)                                                           \
    cerr << __LINE__ << " :: ", _DEBUG_UTIL_::printerArr(#arr, arr, n)
#else
#define dbg(x...)
#define dbgA(arr, n)
#endif

#define ff first
#define ss second
#define All(x) (x).begin(), (x).end()
#define Allr(x) (x).rbegin(), (x).rend()
#define sz(x) static_cast<int>(x.size())
#define vi vector<int>
#define pi pair<int, int>
typedef long long ll;
typedef long double ld;

const int mod = 1000000007; // 1000000007 998244353
const ll inf = 1e18;

template <typename Func> class FUN_res {
    Func func_;

public:
    template <typename T>
    explicit FUN_res(T&& func) : func_(std::forward<T>(func)) {}
    template <typename... Args> decltype(auto) operator()(Args&&... args) {
        return func_(std::ref(*this), std::forward<Args>(args)...);
    }
};
template <typename Func> decltype(auto) FUN(Func&& func) {
    return FUN_res<std::decay_t<Func>>(std::forward<Func>(func));
}

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int,int>>>adj(n);
        adj[0].push_back({firstPerson,0});
        adj[firstPerson].push_back({0,0});
        for(auto i:meetings)
        {
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        queue<pair<int,int>>q;
        q.push({0,0});
// time at which the node has recieved a Secret
        vector<int>SecretRecivedAtTime(n,INT_MAX);
        SecretRecivedAtTime[0]=0;
        while(!q.empty())
        {
            int u=q.front().first;
            int curTime=q.front().second;
            q.pop();
            for(auto node:adj[u])
            {
                int v=node.first;
                int t=node.second;
/* check if visiting time is greater than or equal to current time also
check if v has received the Secret before the visiting time if has then no need to push it inside the queue */
                if(curTime<=t && t<SecretRecivedAtTime[v] )
                {
                    q.push({v,t});
                    SecretRecivedAtTime[v]=t;
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(SecretRecivedAtTime[i]!=INT_MAX)ans.push_back(i);
        }
        return ans;
    }
};
void solve() {
    // dbg(Solution().findAllPeople);
}

#ifdef LOCAL
int32_t main() {
    solve();
    return (int)0;
}
#endif