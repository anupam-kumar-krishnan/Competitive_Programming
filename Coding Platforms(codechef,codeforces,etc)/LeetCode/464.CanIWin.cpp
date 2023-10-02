//Question Link --> https://leetcode.com/problems/can-i-win/description/

class Solution {
public:
    vector<vector<int>> dp;
    bool solve(int mx,int target,int sum,int mask,int first){
      //Base Case
        if(first && sum >= target) return false;
        if(sum >= target) return true;

        if(dp[first][mask] != -1) return dp[first][mask];

        if(first){
            for(int i=1; i<=mx; ++i){
                if(mask&(1 << i)) continue;
                int newMask = mask | (1 << i);
              
                if(solve(mx,target,sum+i,newMask,!first) == true) return dp[first][mask] = true;
            }
            return dp[first][mask] = false;
        }
      
        for(int i=1; i<=mx; ++i){
            if(mask&(1 << i)) continue;
            int newMask = mask | (1 << i);
          
            if(solve(mx,target,sum+i,newMask,!first) == false) return dp[first][mask] = false;
        }
      
        return dp[first][mask] = true;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal){
        if(desiredTotal == 0) return true;
        if(maxChoosableInteger*(maxChoosableInteger+1)/2 < desiredTotal) return false;
      
        dp = vector<vector<int>> (2,vector<int> (1 << maxChoosableInteger + 1, -1));
        return solve(maxChoosableInteger,desiredTotal,0,0,1);
    }
};
