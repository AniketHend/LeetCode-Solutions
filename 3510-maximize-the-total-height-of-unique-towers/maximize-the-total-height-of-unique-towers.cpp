// 7 6 6 6 6 5 3 2
class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        int n = maximumHeight.size();
        sort(maximumHeight.begin(),maximumHeight.end());
        for(int i=n-2;i>=0;i--)
        {
                maximumHeight[i] = min(maximumHeight[i],maximumHeight[i+1] - 1);
        }

        // for(int i=0;i<n;i++) cout<<maximumHeight[i]<<" ";

        if(maximumHeight[0] <= 0)
            return -1;
        else
        {
            long long su = 0;
            for(int i:maximumHeight)
                su+=i;
            return su;
        }
    }
};