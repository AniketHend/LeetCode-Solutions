class Solution {
public:
    int pivotInteger(int n) {
        int sum = (n*(n + 1))/2;
        int psum=0;
        for(int i=0;i<n;i++) {
            sum-=(i+1);
            if(sum==psum) return i+1;
            psum+=(i+1);
        }
        return -1;
    }
};