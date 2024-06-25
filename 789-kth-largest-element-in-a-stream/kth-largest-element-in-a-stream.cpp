class KthLargest {
    multiset<int> st;
    int K;
    void contract() {
        while (!st.empty() && st.size() > K) {
            st.erase(st.begin());
        }
    }

public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (auto& num : nums)
            st.insert(num);
        contract();
    }

    int add(int val) {
        st.insert(val);
        contract();
        return *(st.begin());
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */