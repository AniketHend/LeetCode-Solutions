#define ll long long 
int spf[1000001];

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        map<ll,ll>mp;
        for(int i = 0;i<nums1.size();i++){
            for(ll div = 1;div*div<=nums1[i];div++){
                if(nums1[i]%div==0){
                    int first = nums1[i]/div;
                    int second = div;
                    if(first == second){
                        mp[div]++;
                    }else{
                        mp[first]++;mp[second]++;
                    }
                }
            }
        }
        ll cnt = 0;
        for(int i =0;i<nums2.size();i++){
            ll val = k*nums2[i];
            cnt+= mp[val];
        }
        return cnt;
        
    }
};