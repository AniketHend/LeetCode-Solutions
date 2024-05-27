class Solution {
    public int minimumXORSum(int[] nums1, int[] nums2) {
        // dp with bitmasking , write recursive
        int states = 1 << nums1.length;
        int dp[] = new int[states];
        Arrays.fill(dp, -1);
        xorf(nums1, nums2, dp, 0, 0);
        System.out.println(Arrays.toString(dp));
        return dp[0];
    }

    public static int xorf(int nums1[], int nums2[], int dp[], int bitmask, int idx) {
        if (idx == nums1.length)
            return 0;
        if (dp[bitmask] != -1)
            return dp[bitmask];

        int ans = (int) 1e9;

        for (int i = 0; i < nums2.length; i++) {
            if ((bitmask & (1 << i)) > 0)
                continue;
            ans = Math.min((nums1[idx] ^ nums2[i]) + xorf(nums1, nums2, dp, (bitmask | (1 << i)), idx + 1),ans);
        }
        return dp[bitmask] = ans;
    }
}
//152 167 175 167 167 207 167 120 164 206 164 117 204 157 123 92 125 165 125 76 165 116 76 51 162 119 73 54 113 110 48 2147483647 
