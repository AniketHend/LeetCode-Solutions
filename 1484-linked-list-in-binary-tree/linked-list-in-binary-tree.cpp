/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool solve(ListNode* head, TreeNode* root, ListNode* temp) {
        if (temp == nullptr)
            return true;
        if (root == nullptr)
            return false;
        if (temp->val == root->val) {
            temp = temp->next;
        } else if(head->val == root->val){
            head = head->next;
        } else {
            temp = head;
        }
        return solve(head,root->left,temp) || solve(head,root->right,temp);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        return solve(head, root, head);
    }
};
