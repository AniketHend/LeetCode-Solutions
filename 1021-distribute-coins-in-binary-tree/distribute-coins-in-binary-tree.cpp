class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int m = 0;
        distributeCoins(root, m);
        return m;
    }

private:
    int distributeCoins(TreeNode* root, int& m) {
        if (root == NULL)
            return 0;
        int r = distributeCoins(root->right,m);
        int l = distributeCoins(root->left,m);
        m += abs(l) + abs(r);
        return root->val + l + r - 1;
    }
};