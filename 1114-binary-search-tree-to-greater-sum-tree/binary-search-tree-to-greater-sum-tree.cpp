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
    vector<int> data, pref;
    void bstToGst1(TreeNode* root) {
        if (!root) {
            return;
        }
        bstToGst1(root->left);
        data.push_back(root->val);
        bstToGst1(root->right);
    }
    void f(TreeNode* rt) {
        if (!rt)
            return;
        f(rt->left);
        f(rt->right);
        int ind = lower_bound(data.begin(), data.end(), rt->val) - data.begin();
        ind--;
        int to = pref.back() - (ind >= 0 ? pref[ind] : 0);
        rt->val = to;
    }

public:
    TreeNode* bstToGst(TreeNode* root) {
        bstToGst1(root);
        pref = data;
        for (int i = 1; i < data.size(); i++)
            pref[i] += pref[i - 1];
        f(root);
        return root;
    }
};