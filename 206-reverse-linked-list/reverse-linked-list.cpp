using T = ListNode*;
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        T new_head = reverseList(head->next);
        T nxt = head->next;
        nxt->next = head;
        head->next = NULL;
        return new_head;
    }
};