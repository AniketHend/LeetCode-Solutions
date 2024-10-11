class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {

        int n = times.size();
        int target = times[targetFriend][0];

        sort(times.begin(), times.end());

        priority_queue<int, vector<int>, greater<int>> avl;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            unavl;

        for (auto& i : times) {

            while (!unavl.empty() && unavl.top().first <= i[0]) {
                avl.push(unavl.top().second);
                unavl.pop();
            }

            if (i[0] == target) {
                break;
            }

            if (avl.empty()) {
                unavl.push({i[1], unavl.size()});
            }

            else {
                unavl.push({i[1], avl.top()});
                avl.pop();
            }
        }

        return avl.empty() ? unavl.size() : avl.top();
    }
};