class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        stack<pair<int, int>> st;
        ListNode* cr = head;

        map<int, int> mp;
        mp[0]++;
        int psum = 0;
        while (cr != NULL) {
            int v = cr->val;
            psum += v;
            if (st.empty()) {
                if(psum==0) {
                    cr=cr->next;
                    continue;
                }
                st.push({v, psum});
                mp[psum]++;
            } else {
                if (mp.find(psum) != mp.end()) {
                    while (!st.empty()) {
                        auto tp = st.top();
                        if (tp.second == psum)
                            break;
                        mp[tp.second]--;
                        if (mp[tp.second] == 0)
                            mp.erase(tp.second);
                        st.pop();
                    }
                } else {
                    st.push({v, psum});
                    mp[psum]++;
                };
            }
            cr = cr->next;
        }
        vector<int> v;
        while (!st.empty()) {
            v.push_back(st.top().first);
            st.pop();
        }
        reverse(v.begin(), v.end());
        head = NULL;
        if (v.empty())
            return head;
        head = new ListNode(v[0]);
        ListNode* f = head;
        for (int i = 1; i < v.size(); i++) {
            f->next = new ListNode(v[i]);
            f = f->next;
        }
        return head;
    }
};