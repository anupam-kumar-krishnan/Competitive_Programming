class Solution {
public:
    
    void solve(int ind, int n, int k, vector<vector<int>>&ans, vector<int>&row){
        if( k==0){
            ans.push_back(row);
            return ;
        }
        if(n==0) return ;
        
        for(int i=ind; i<=n; i++){
            row.push_back(i);
            solve(i+1,n,k-1,ans,row);
            row.pop_back();
        }
        
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>row;
        solve(1,n,k,ans,row);
        return ans;
    }
};
