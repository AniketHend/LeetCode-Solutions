static const int _ = []() {ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0;}();

class Solution {
public:
    vector<int> sortJumbled(vector<int>& M, vector<int>& nums) {
        vector<pair<int, int>> vp;
        for (int i = 0; i < nums.size(); ++i)
            vp.push_back({nums[i], i});
        sort(vp.begin(), vp.end(), [&](const auto& a, const auto& b) {
            int num1 = 0, num2 = 0;
            int x = a.first;
            int y = b.first;
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
            if (num1 == num2)
                return a.second < b.second;
            return num1 < num2;
        });
        nums.clear();
        for (auto it : vp)
            nums.push_back(it.first);
        return nums;
    }
};