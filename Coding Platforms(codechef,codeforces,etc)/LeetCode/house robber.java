public class Solution {
    public int rob(int[] nums) {
        if(nums ==null || nums.length == 0) return 0;
        if(nums.length == 1) return nums[0];

        int prev=0; // res[i-1]
        int cur=0; // res[i];


        for(int i=0; i< nums.length;i++){
            int m = prev, n = cur;
            cur = prev + nums[i];
            prev = Math.max(m,n);
        }

        return Math.max(cur,prev);
    }
}
