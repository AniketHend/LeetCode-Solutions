class Solution {
    public int minKBitFlips(int[] nums, int k) {
        int n = nums.length;
        int fl = 0;
        int dp[] = new int[2*n+5];

        for(int i=0;i<n;i++) {
            if(i>0) dp[i]+=dp[i-1];
            int y = dp[i];
            int bit = nums[i]^(y%2);
            if(bit == 0) {
                fl++;
                dp[i]++;
                if(i+k>n) return -1;
                dp[i+k]--;
            }
        }
        return fl;
    }
}