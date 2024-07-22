using T = TreeNode*;
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return NULL;
        T lft = lowestCommonAncestor(root->left, p, q);
        T rht = lowestCommonAncestor(root->right, p, q);

        if (root->val == p->val && lft != NULL && lft->val == q->val) {
            return root;
        }
        if (root->val == q->val && lft != NULL && lft->val == p->val) {
            return root;
        }

        if (root->val == p->val && rht != NULL && rht->val == q->val) {
            return root;
        }
        if (root->val == q->val && rht != NULL && rht->val == p->val) {
            return root;
        }
        if (lft != NULL && rht != NULL &&
            ((lft->val == p->val && rht->val == q->val) ||
             (rht->val == p->val && lft->val == q->val))) {
            return root;
        }
        if(rht != NULL) {
            return rht;
        }
        if(lft != NULL) {
            return lft;
        }
        if(root->val == p->val || root->val == q->val) return root;
        return NULL;
    }
};