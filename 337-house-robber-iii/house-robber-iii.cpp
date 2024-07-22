class Solution {
    map<TreeNode*,int> dp;
public:
    int rob(TreeNode* root) {
        if (!root)
            return 0;
        if(dp.count(root)) return dp[root];
        int pick = root->val;
        int x = 0;
        if (root->left) {
            x = rob(root->left->left) + rob(root->left->right);
        }
        if (root->right) {
            x += rob(root->right->left) + rob(root->right->right);
        }
        pick += x;
        int notpick = rob(root->left) + rob(root->right);
        return dp[root] = max(pick, notpick);
    }
};