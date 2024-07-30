class Solution {
public:
  int minimumDeletions(string s) {
    int ans = INT_MAX;
    int pre[2] = {0, 0};
    int suf[2] = {0, 0};
    for (char ch : s) suf[ch - 'a']++;
    for (int i = 0; i < s.size(); i++) {
      // ithun b
      suf[s[i]-'a']--;
      int x = pre[1];
      int y = suf[0];
    //   cout << i <<" " << j <<" "
      pre[s[i]-'a']++;
      ans=min(ans,x+y);
    }
    return ans;
  }
};