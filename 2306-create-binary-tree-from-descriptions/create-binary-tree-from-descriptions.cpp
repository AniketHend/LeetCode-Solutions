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
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        map<int, TreeNode*> mp;
        map<int, int> ind;
        for (auto edge : d) {
            if (!mp.count(edge[0]))
                mp[edge[0]] = new TreeNode(edge[0]);
            if (!mp.count(edge[1]))
                mp[edge[1]] = new TreeNode(edge[1]);
            ind[edge[1]]++;
        }
        int rt = -1;
        for (auto e : d) {
            if (!ind.count(e[0]))
                rt = e[0];
        }
        for (auto e : d) {
            if(e[2] == 0) {
                mp[e[0]]->right = mp[e[1]];
            } else {
                mp[e[0]]->left = mp[e[1]];
            }
        }

        return mp[rt];
    }
};