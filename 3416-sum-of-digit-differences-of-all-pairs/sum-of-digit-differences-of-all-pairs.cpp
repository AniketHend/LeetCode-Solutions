class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return 0;
        int numDigits = to_string(nums[0]).size();
        vector<vector<int>> digitCount(numDigits, vector<int>(10, 0));
        for (const int& num : nums) {
            string strNum = to_string(num);
            for (int i = 0; i < numDigits; ++i) {
                digitCount[i][strNum[i] - '0']++;
            }
        }
        long long int totalDifference = 0;
        for (int i = 0; i < numDigits; ++i) {
            for (int d1 = 0; d1 < 10; ++d1) {
                for (int d2 = d1 + 1; d2 < 10; ++d2) {
                    totalDifference += digitCount[i][d1] * digitCount[i][d2];
                }
            }
        }
        return totalDifference;
    }
};
