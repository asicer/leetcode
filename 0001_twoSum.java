import java.util.HashMap;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] res = new int[2];
        if (nums == null || nums.length < 1) return res;
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; i++) {
            int num = nums[i];
            int val = target - num;
            if (map.containsKey(val)) {
                res[0] = i;
                res[1] = map.get(val);
                return res;
            } else map.put(num, i);
        }
        return res;
    }

    public static void main(String args[]) { 
        int[] nums = {2, 7, 11, 15};
        int target = 9;
        Solution s = new Solution();
        int[] res = s.twoSum(nums, target);
        System.out.println(res[0] + ", " + res[1]);
    } 
}
