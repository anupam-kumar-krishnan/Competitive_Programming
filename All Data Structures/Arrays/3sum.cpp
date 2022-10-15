class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        set<vector<int>>ans;
        for(int i=0;i<nums.size();i++){
            
            int x=-1*nums[i];
            
            
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                
                if(nums[j]+nums[k]==x){
                    
                    vector<int>a;
                ans.insert({-1*x,nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if(nums[j]+nums[k]>x){
                    
                    k--;
                }
                else{
                    j++;
                }
                
            }
            
            
        }
        vector<vector<int>>lans;
        
        for(auto i : ans){
            
            lans.push_back(i);
        }
        return lans;
        
    }
};
