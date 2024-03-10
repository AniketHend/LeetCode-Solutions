class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        set<int> s, s1;
        for (auto& i : nums1)
            s.insert(i);
        for (auto& i : nums2)
            s1.insert(i);
        for (auto& i : s)
            if (s1.find(i) != s1.end()) {
                res.push_back(i);
            }
        return res;
    }
};