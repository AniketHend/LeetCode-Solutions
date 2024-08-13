class Solution {
    public List<List<Integer>> combinationSum2(int[] c, int target) {
        Arrays.sort(c);
        List<List<Integer>> ans = new ArrayList<>();
        comb(0, c, target, new ArrayList<>(), ans);
        return ans;
    }

    public static void comb(int idx, int a[], int t, List<Integer> ds, List<List<Integer>> ans) {
        if (t == 0) {
            ans.add(new ArrayList<>(ds));
            return;
        }
        for (int i = idx; i < a.length; i++) {
            if (i > idx && a[i] == a[i - 1]) {
                continue;
            }
            if (a[i] > t) {
                break;
            }
            ds.add(a[i]);
            comb(i + 1, a, t - a[i], ds, ans);
            ds.remove(ds.size() - 1);
        }
    }
}