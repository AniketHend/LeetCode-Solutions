using T = ListNode*;
class Solution {
public:
    ListNode* reverseList(ListNode* head) { 
        T prs = NULL, cur = head; 
        while(cur) {
            T nxt = cur->next;
            cur->next = prs;
            prs = cur;
            cur = nxt;
        }
        return prs;
    }
};