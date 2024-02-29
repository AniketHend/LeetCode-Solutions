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
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int lvl = 1;
        while (!q.empty()) {
            int sz = q.size();
            int p = 0;
            int qq = INT_MAX;
            for (int i = 0; i < sz; i++) {
                if (q.front()->val % 2 != lvl)
                    return false;
                if (lvl && q.front()->val >= qq)
                    return false;
                if (!lvl && q.front()->val <= p)
                    return false;
                p = q.front()->val;
                qq = q.front()->val;
                if (q.front()->right != NULL)
                    q.push(q.front()->right);
                if (q.front()->left != NULL)
                    q.push(q.front()->left);
                q.pop();
            }
            lvl ^= 1;
        }
        return true;
    }
};