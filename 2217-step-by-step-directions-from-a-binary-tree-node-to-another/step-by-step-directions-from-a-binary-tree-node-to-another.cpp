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
    bool dfs(TreeNode* rt, string& path, int d) {
        if (!rt)
            return false;
        if (rt->val == d) {
            return true;
        }
        if (rt->left) {
            path += "L";
            bool res = dfs(rt->left, path, d);
            if (res) {
                return true;
            }
            path.pop_back();
        }
        if (rt->right) {
            path += "R";
            bool res = dfs(rt->right, path, d);
            if (res) {
                return true;
            }
            path.pop_back();
        }
        return false;
    }

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string s2,s1;
        dfs(root,s1,startValue);
        dfs(root,s2,destValue);
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        while (!s2.empty() && !s1.empty()) {
            if (s2.back() == s1.back())
                s1.pop_back(), s2.pop_back();
            else
                break;
        }
        reverse(s2.begin(), s2.end());
        return string(s1.size(), 'U') + s2;
    }
};