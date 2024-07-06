class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& a) {
        int sa=0;
        int n=a.size();
        for(int i=0;i<n;i++){
            if(a[i%n]==0 && a[(i+1)%n]==1 && a[(i+2)%n]==0)sa++;
            if(a[i%n]==1 && a[(i+1)%n]==0 && a[(i+2)%n]==1)sa++;
        }
        return sa;
    }
};