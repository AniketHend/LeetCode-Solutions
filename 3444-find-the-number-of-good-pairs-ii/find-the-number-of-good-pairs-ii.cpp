class Solution {
public: 
    
   long long funcy(int num , unordered_map<long long,long long>&mp ){
       long long x=0;
       for(int j = 1; (long long)j * j <= num; ++j) {
                if(num % j == 0) {
                    if(mp.find(j) != mp.end()) {
                        x += mp[j];
                    }
                    if(j != num / j && mp.find(num / j) != mp.end()) {
                        x+= mp[num / j];
                    }
                }
            } 
       
       return x ; 
   }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
            unordered_map<long long, long long> mp; 
        for(int num : nums2) {
            mp[(long long)num * k]++;
        }

        long long result = 0;
        for(int i=0;i<nums1.size();i++) {
            result+=funcy(nums1[i],mp);
        }
        return result;
    }
};