class Solution {
public:
    long long int fun(int n,int r,vector<vector<long long int>>&dp){
        if(n==r) return 1;
        if(r==0) return 1;
        
        if(dp[n][r]!=-1) return dp[n][r];
        return dp[n][r]=fun(n-1,r,dp)+0LL+fun(n-1,r-1,dp);
    }
    int numTrees(int n) {
        
        int a=2*n;
        vector<vector<long long int>>dp(a+3,vector<long long int>(n+2,-1));
        return fun(a,n,dp)/(n+1);
        
    }
};
