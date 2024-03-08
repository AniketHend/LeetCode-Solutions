class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> v(101,0);
        for(auto &i:nums) v[i]++;
        int m=*max_element(v.begin(),v.end());
        int x=count(v.begin(),v.end(),m);
        return x*m;
    }
};