class Solution {
   public int lengthOfLIS(int[] nums) {
    if(nums==null || nums.length==0)
        return 0;
 
    int[] max = new int[nums.length];
    Arrays.fill(max, 1);
 
    int result = 1;
    for(int i=0; i<nums.length; i++){
        for(int j=0; j<i; j++){
            if(nums[i]>nums[j]){
                max[i]= Math.max(max[i], max[j]+1);
 
            }
        }
        result = Math.max(max[i], result);
    }
 
   return result;
        }}
