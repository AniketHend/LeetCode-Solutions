static const int _ = []() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while(right>left) right&=(right-1);
        return right;
    }
};