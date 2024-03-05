static const int _ = []() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();

class Solution {
public:
    int minimumLength(string s) {
        int i = 0, j = s.size() - 1;
        cout << s.size() << endl;
        while (i < j) {
            char c_char = s[i];
            if(s[i] != s[j]) break;
            while(i<s.size() && s[i]==c_char) i++;
            while(j>=0 && s[j]==c_char) j--;
        }
        return max(0, j - i + 1);
    }
};