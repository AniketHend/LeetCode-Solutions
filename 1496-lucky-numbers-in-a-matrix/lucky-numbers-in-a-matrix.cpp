class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        vector<int> r(n),c(m);
        for(int i=0;i<n;i++) {
            int mc=1e6,cnt=0;
            for(int j=0;j<m;j++) {
                mc=min(mc,a[i][j]);
            }
            r[i]=mc;
        }
        for(int i=0;i<m;i++) {
            int mc=0,cnt=0;
            for(int j=0;j<n;j++) {
                mc=max(mc,a[j][i]);
            }
            c[i]=mc;
        }
        vector<int> sa;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(a[i][j]==r[i] && a[i][j]==c[j]) {
                    sa.push_back(a[i][j]);
                }
            }
        }
        return sa;
    }
};

static const int _ = []() {ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0;}();
