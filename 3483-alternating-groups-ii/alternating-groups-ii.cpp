class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        vector<int> col;
        for(auto i:colors) col.push_back(i);
        for(auto i:colors) col.push_back(i);
        int y = 0,z=0;
        int n = col.size();
        int p = 0;
        int cr = col[0]^1;
        for(int i=1;i<n;i++) {
            if(cr==col[i]) {
                cr^=1;

                if(i-p+1==k) {
                    if(p<=n/2-1 && i<=n/2-1) z++;   
                    y++,p++;
                }
            } else {
                p=i;
                cr=col[i]^1;
            }
        }
        // cout<<z<<endl;
        return y-z;
    }
};