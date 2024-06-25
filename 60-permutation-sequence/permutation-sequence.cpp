class Solution {
public:
    string getPermutation(int n, int k) {
        string s = "";
        for (int i = 1; i <= n; i++)
            s += char(i + '0');
        do {
            k--;
            if (k == 0)
                return s;
        } while (next_permutation(s.begin(), s.end()));
        return s;
    }
};