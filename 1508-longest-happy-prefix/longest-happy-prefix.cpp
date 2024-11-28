class Solution {
    vector<int> z_algo(string s) {
	int n = s.size();
	vector<int> z(n);
	for (int i = 1, l = 0, r = 0; i < n; i++) {
		if (i <= r) z[i] = min(z[i - l], r - i + 1);
		while (i + z[i] < n && s[i + z[i]] == s[z[i]])z[i]++;
		if (i + z[i] - 1 >= r) l = i, r = i + z[i] - 1;
	}
	return z;
}


public:
    string longestPrefix(string s) {
        vector<int> z = z_algo(s);
        int n=s.size();
        for(int i=1;i<n;i++) {
            if(i+z[i]==n) return s.substr(0,z[i]);
        }
        return "";
    }
};