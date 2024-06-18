static const bool Init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    return true;
}();

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
