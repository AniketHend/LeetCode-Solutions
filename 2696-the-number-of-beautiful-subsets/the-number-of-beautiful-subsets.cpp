class Solution {
public:
    unordered_map<int, int> freq;
    void solve(int index, vector<int>& arr, int& ans, int& k) {
        if (index >= arr.size()) {
            ans++;
            return;
        }
        solve(index + 1, arr, ans, k); // Not take and just skip
        if (freq[(arr[index] - k)] == 0 &&
            freq[abs(arr[index] + k)] == 0) // If valid then take it
        {
            freq[arr[index]]++; // add the element in the map freq
            solve(index + 1, arr, ans, k);
            freq[arr[index]]--; // backtrack and solve if the current element
                                // was not chosen
        }
    }
    int beautifulSubsets(vector<int>& arr, int k) {
        int ans = 0;
        int index = 0;
        solve(index, arr, ans, k);
        return ans - 1; // since empty subset is also counted when all choose to
                        // not take
    }
};