class Solution {
    array<int, 2> robb(TreeNode* root) {
        if (!root)
            return {0, 0};
        auto lft = robb(root->left);
        auto rht = robb(root->right);
        array<int, 2> c = {0, 0};
        c[0] = root->val + lft[1] + rht[1];
        c[1] = max(rht[0], rht[1]) + max(lft[0], lft[1]);
        // cout << root->val << " " << c[0] << " " << c[1] << endl;
        return c;
    }

public:
    int rob(TreeNode* root) {
        array<int, 2> c = robb(root);
        return max(c[0], c[1]);
    }
};