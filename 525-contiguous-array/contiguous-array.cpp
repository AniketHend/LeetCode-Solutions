class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int s=0;
        unordered_map<int,int> m; 
        int n = nums.size();
        int ans=0;
        for(int i=0;i<n;i++) {
            s-=(nums[i]==0);
            s+=(nums[i]==1);
            if(s==0) {
                ans=i+1;
            }
            else if(m.find(s)!=m.end()) {
                ans=max(ans,i-m[s]);
            } else {
                m[s]=i;
            }
        }
        return ans;
    }
};