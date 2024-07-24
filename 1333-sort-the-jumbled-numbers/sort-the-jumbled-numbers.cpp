static const int _ = []() {ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0;}();

class Solution {
public:
    vector<int> sortJumbled(vector<int>& M, vector<int>& nums) {
        sort(nums.begin(), nums.end(), [M](const auto& a, const auto& b) {
            int num1 = 0, num2 = 0;
            int x = a;
            int y = b;
            int yp = 1;
            if(x == 0) num1 = M[0];
            while (x) {
                num1 += M[x % 10] * yp, x /= 10, yp *= 10;
            }
            yp = 1;
            if(y == 0) num2 = M[0];
            while (y) {
                num2 += M[y % 10] * yp, y /= 10, yp *= 10;
            }
            return num1 < num2;
        });
        return nums;
    }
};