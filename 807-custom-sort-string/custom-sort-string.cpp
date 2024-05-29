class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> index(26, -1);
        for (int i = 0; i < order.size(); i++) {
            index[order[i] - 'a'] = i;
        }

        sort(s.begin(), s.end(), [&index](char ch1, char ch2) {
            int i1 = index[ch1 - 'a'], i2 = index[ch2 - 'a'];
            if (i1 != -1 && i2 != -1) {
                return i1 < i2;
            } else if (i1 != -1) {
                return true;
            } else if (i2 != -1) {
                return false;
            } else {
                return ch1 < ch2; // If neither character is in order, maintain
                                  // the original order
            }
        });
        return s;
    }
};