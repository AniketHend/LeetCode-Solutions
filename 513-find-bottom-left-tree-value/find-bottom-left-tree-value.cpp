
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            int ok = 0;
            int sa = -2;
            for (int i = 0; i < sz; i++) {
                auto tp = q.front();
                q.pop();
                if (sa == -2)
                    sa = tp->val;
                if (tp->left != NULL) {
                    ok = 1;
                    q.push(tp->left);
                }
                if (tp->right != NULL) {
                    ok = 1;
                    q.push(tp->right);
                }
            }
            if (!ok)
                return sa;
        }
        return -1;
    }
};