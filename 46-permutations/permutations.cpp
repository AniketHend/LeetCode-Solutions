class Solution {
public:
    vector<vector<int>> permute(vector<int>& s) {
        vector<vector<int>> sa;
        sort(s.begin(), s.end());
        do {
            sa.push_back(s);
        } while (next_permutation(s.begin(), s.end()));
        return sa;
    }
};