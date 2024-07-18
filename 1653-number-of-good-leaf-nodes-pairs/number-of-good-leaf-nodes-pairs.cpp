/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

using T = TreeNode*;
class Solution {
public:
    int countPairs(T root, int d) {
        int ans = 0;
        auto dfs = [&](auto&& dfs, T u) -> vector<int> {
            vector<int> dp(d + 1);
            if (!u) {
                return dp;
            }
            if (u->left == NULL && u->right == NULL) {
                dp[1] = 1;
                return dp;
            }
            vector<int> hp(d + 1);
            auto lft = dfs(dfs, u->left);
            auto rht = dfs(dfs, u->right);
            int y = 0;
            for (int j = 1; j <= d; j++) {
                for (int i = 0; i <= j; i++) {
                    y += lft[j - i] * rht[i];
                    if (i && j == d)
                        hp[i] = lft[i - 1] + rht[i - 1];
                }
            }
            /*
            cout << u->val << " :: \n";
            for (auto i : lft)
                cout << i << " ";
            cout << endl;
            for (auto i : rht)
                cout << i << " ";
            cout << endl;
            for (auto i : rht)
                cout << i << " ";
            cout << endl;*/
            ans += y;
            return hp;
        };
        dfs(dfs, root);
        return ans;
    }
};