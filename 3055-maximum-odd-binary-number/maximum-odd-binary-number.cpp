class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string sa="";
        int c = count(s.begin(),s.end(),'1');
        sa+='1';
        c--;
        int rem = s.size()-1-c;
        for(int i=0;i<rem;i++) sa+='0';
        for(int i=0;i<c;i++) sa+='1';
        reverse(sa.begin(),sa.end());
        return sa;
    }
};