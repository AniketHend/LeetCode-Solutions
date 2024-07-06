class Solution {
public:
    long long maximumPoints(vector<int>& nums, int currentEnergy) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long y=currentEnergy;
        for(int i=1;i<n;i++){
            y+=nums[i];
        }
        if(currentEnergy<nums[0])return 0;
        return y/nums[0];
    }
};