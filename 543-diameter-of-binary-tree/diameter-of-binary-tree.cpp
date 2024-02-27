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
class Solution {
    pair<int, int> f(TreeNode* root) {
        if (root == NULL)
            return {0, 0};
        auto r = f(root->right);
        auto l = f(root->left);
        // cout<<root->val<<" "<<max(max(l.first, r.first), l.second + r.second + 1)<<endl;
        return {max(max(l.first, r.first), l.second + r.second + 1),
                1 + max(l.second, r.second)};
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        return f(root).first-1;
    }
};