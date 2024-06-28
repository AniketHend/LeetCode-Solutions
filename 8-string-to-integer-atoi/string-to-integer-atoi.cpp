class Solution {
public:
    int myAtoi(string s) {
        long long num = 0, ok = 0;
        int j = 0;
        while (s[j] == ' ')
            j++;
        if (s[j] == '-') {
            ok++, j++;
        } else if (s[j] == '+') {
            ok = 0, j++;
        }
        for (int i = j; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9'){   
                num *= 10LL, num += (s[i] - '0');
                if (num < INT_MIN) {
                    num = INT_MIN*pow(-1,ok);
                    if(num<0) num++;
                    return num;
                }
                if (num > INT_MAX) {
                    num=INT_MAX*pow(-1,ok);
                    if(num<0) num--;
                    return num;
                }
            }
            else
                break;
        }
        if (ok)
            num *= -1LL;
        if (num < INT_MIN)
            num = INT_MIN;
        if (num > INT_MAX)
            num = INT_MAX;
        return num;
    }
};