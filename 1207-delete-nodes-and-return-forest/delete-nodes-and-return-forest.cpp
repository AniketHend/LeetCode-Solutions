#define T TreeNode*

class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<T> sa;
        set<pair<int, T>> got;
        set<T> got1;

        queue<pair<int, T>> q;
        map<T, T> par;
        set<int> del;

        for (int i : to_delete)
            del.insert(i);
        q.push({0, root});
        par[root] = NULL;
        got.insert({0, root});

        while (!q.empty()) {
            T cur = q.front().second;
            int lvl = q.front().first;
            q.pop();
            int x = cur->val;
            if (cur->left) {
                par[cur->left] = cur;
                got.insert({lvl + 1, cur->left});
                q.push({lvl + 1, cur->left});
            }
            if (cur->right) {
                par[cur->right] = cur;
                got.insert({lvl + 1, cur->right});
                q.push({lvl + 1, cur->right});
            }
            if (del.count(x)) {
                got.erase({lvl, cur});
                if (par[cur]) {
                    if (par[cur]->left == cur)
                        par[cur]->left = NULL;
                    else
                        par[cur]->right = NULL;
                }
                cur->left = NULL;
                cur->right = NULL;
            }
        }

        set<T> got_new;

        auto dfs = [&](auto&& dfs, T c) -> void {
            if (got1.count(c)) {
                got1.erase(c);
            }
            if (c->left)
                dfs(dfs, c->left);
            if (c->right)
                dfs(dfs, c->right);
        };

        for (auto it : got) {
            got1.insert(it.second);
        }
        for (auto it : got) {
            if (got1.count(it.second)) {
                dfs(dfs, it.second);
                sa.push_back(it.second);
            }
        }
        return sa;
    }
};
