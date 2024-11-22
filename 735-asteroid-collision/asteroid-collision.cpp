class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> st;

        for(int i:a) {
            int cur = i;
            int ok = 0;
            while(!st.empty() && st.top()>0 && cur<0) {
                if(st.top() > abs(cur)){
                    cur = st.top();
                } else if(st.top() == abs(cur)){
                    ok = 1; 
                    st.pop();
                    break;
                }
                st.pop();
            }
            if(!ok) {
                st.push(cur);
            }
        }
        vector<int> sa;
        while(!st.empty()) sa.push_back(st.top()),st.pop();
        reverse(sa.begin(),sa.end());
        return sa;
    }
};