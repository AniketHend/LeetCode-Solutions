class Solution {
public:
    bool isHappy(int n) {
        map<int, int> mp;
        mp[n]++;
        int x = n;
        while (x) {
            if (x == 1)
                break;
            if (mp[x] > 1)
                break;
            int s = 0;
            while (x > 0) {
                s = s + ((x % 10) * (x % 10));
                x = x / 10;
            }
            mp[s]++;
            x = s;
        }
        if (x == 1)
            return 1;
        return 0;
    }
};