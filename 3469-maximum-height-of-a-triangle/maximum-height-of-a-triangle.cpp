class Solution {
public:
    int solve(int a, int b) {
        int height = 0;
        int reda = a;
        int blueb = b;
        int i = 1;
        while (true) {
            if (i % 2 == 1) {
                if (reda >= i) {
                    reda -= i;

                } else {
                    break;
                }
            } else {
                if (blueb >= i) {
                    blueb -= i;
                } else {
                    break;
                }
            }

            i++;
            height++;
        }
        return height;
    }
    int maxHeightOfTriangle(int red, int blue) {
        int ans = solve(red, blue);
        ans = max(solve(blue, red), ans);
        return ans;
    }
};