class Solution {
    public long[] maximumSegmentSum(int[] nums, int[] removeQueries) {

        int n = nums.length;
        long[] ans = new long[n];

        int arr[] = new int[n];
        int size[] = new int[n];
        long value[] = new long[n];

        for (int i = 0; i < n; i++) {
            value[i] = nums[i];
        }

        Arrays.fill(size, 1);

        int leader[] = new int[n];

        for (int i = 0; i < n; i++)
            leader[i] = i;

        long curAns = 0;

        for (int i = nums.length - 1; i >= 0; i--) {
            ans[i] = curAns;
            arr[removeQueries[i]] = nums[removeQueries[i]];
            int idx = removeQueries[i];

            if (idx > 0 && arr[idx - 1] != 0) {
                merge(leader, idx, idx - 1, size, value);
            }
            if (idx < n - 1 && arr[idx + 1] != 0) {
                merge(leader, idx, idx + 1, size, value);
            }
            shrink(idx, leader);
            curAns = Math.max(curAns, value[leader[idx]]);
        }
        return ans;
    }

    public void merge(int leader[], int u, int v, int size[], long[] value) {
        shrink(u, leader);
        shrink(v, leader);
        if (leader[u] == leader[v])
            return;

        if (size[leader[u]] > size[leader[v]]) {
            size[leader[u]] += size[leader[v]];
            value[leader[u]] += value[leader[v]];
leader[leader[v]] = leader[u];        } else {
            size[leader[v]] += size[leader[u]];
            value[leader[v]] += value[leader[u]];
            leader[leader[u]] = leader[v];
        }

    }

    public void shrink(int u, int leader[]) {
        if (leader[u] == u)
            return;
        shrink(leader[u], leader);
        leader[u] = leader[leader[u]];
    }
}