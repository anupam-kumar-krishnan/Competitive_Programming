  int binarySearch(vector<int>& nums, int target, bool leftMost){
        int low=0,high=nums.size()-1,mid;
        int ans=-1;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]==target){
                ans=mid;
                if(leftMost==true)
                     high=mid-1;
                else
                     low=mid+1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
       int left=binarySearch(nums,target,true);
       int right=binarySearch(nums,target,false);
       if(left<=right)
           return {left,right};
        else
            return{-1,-1};
    }
