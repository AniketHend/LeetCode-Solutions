class Solution {
public:
    int findDuplicate(vector<int>& v) {
        // O(N) -> time complexity && O(1) -> space complexity
        int slow = v[0];
        int fast = v[v[0]];
        while (slow != fast) {
            slow = v[slow];
            fast = v[v[fast]];
        }
        slow = 0;
        while (slow != fast) {
            fast = v[fast];
            slow = v[slow];
        }
        return slow;
    }
};
