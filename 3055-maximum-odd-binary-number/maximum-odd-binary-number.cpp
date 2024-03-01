class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int c = count(s.begin(),s.end(),'1');
        return string(c-1,'1')+string(s.size()-c,'0')+string(1,'1');
    }
};