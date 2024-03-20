#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using omset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

static const int _ = []() {ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0;}();

#ifdef ONLINE_JUDGE
#include "debug.h"
#define dbg(...) cerr << __LINE__ << " :: ", _DEBUG_UTIL_::printer(#__VA_ARGS__, __VA_ARGS__)
#define dbgA(arr, n) cerr << __LINE__ << " :: ", _DEBUG_UTIL_::printerArr(#arr, arr, n)
#else
#define dbg(x...)
#define dbgA(arr, n)
#endif

#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x.size())
#define vl vector<long long>
#define vi vector<int>
#define vll vector<vector<long long>>
#define vii vector<vector<int>>
#define pll pair<long long, long long>
#define pii pair<int ,int>
typedef long long ll;
typedef long double ld;

const int mod = 1000000007; // 1000000007 998244353
const ll inf = 1e18;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeInBetween(ListNode* l1, int a, int b, ListNode* l2) {
#define node ListNode*
        node l2_head = l2;
        node l2_end = l2;
        while (l2_end->next != NULL) l2_end = l2_end->next;

        int node_num = 0;
        node l1_anode = l1;
        node l1_bnode = l1;

        while (node_num < a - 1) {
            node_num++;
            l1_anode = l1_anode->next;
        }
        node_num = 0;
        while (node_num <= b) {
            node_num++;
            l1_bnode = l1_bnode->next;
        }
        l1_anode->next=l2_head;
        l2_end->next = l1_bnode;
        return l1;
    }
};
void solve() {
    // dbg(Solution().leastInterval({1, 0, 1, 0, 1}, 3, 0));
}

#ifdef LOCAL
int32_t main() { solve(); }
#endif
