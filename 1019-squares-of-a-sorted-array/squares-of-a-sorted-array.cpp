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
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> a;
        for (auto &i : nums) i = abs(i);
        int m = min_element(All(nums)) - nums.begin();
        int i = m + 1;
        int j = m-1;
        a.push_back(nums[m]*nums[m]);

        ll n = sz(nums);
        while (true) {
            if (j == -1 && i == n) {
                break;
            }
            if (j >= 0 && i < n) {
                if (nums[j] < nums[i]) a.push_back(nums[j]*nums[j--]);
                else a.push_back(nums[i]*nums[i++]);
            } else if (j>=0) {
                a.push_back(nums[j]*nums[j--]);
            } else {
                a.push_back(nums[i]*nums[i++]);
            }
        }
        return a;
    }
};
void solve() {
    // dbg(Solution().findAllPeople);
}

#ifdef LOCAL
int32_t main() { solve(); }
#endif
