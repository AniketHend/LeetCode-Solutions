import java.util.*;

class Solution {
    void generator(int i, int[] nums, List<Integer> temp,List<List<Integer>> ans) {
        if (i == nums.length) {
            ans.add(new ArrayList<>(temp));
            return;
        }
        generator(i + 1, nums, temp,ans);
        temp.add(nums[i]);
        generator(i + 1, nums, temp,ans);
        temp.removeLast();
    }

    public List<List<Integer>> subsets(int[] nums) {
        List<Integer> temp = new ArrayList<>();
        List<List<Integer>> ans = new ArrayList<>();
        generator(0, nums, temp,ans);
        return ans;
    }
}