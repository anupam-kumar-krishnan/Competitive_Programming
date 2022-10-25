   int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN, sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            maxi=max(sum,maxi);
            if(sum<0) sum=0;
        }
        return maxi;
    }
