#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int buySell2(int i, int buy, int transc, int n, vector<int> &vec, vector<vector<vector<int>>> &dp)
{
  if (i == n)
    return 0;
  if (transc == 0)
    return 0;
  if (dp[i][buy][transc] != -1)
    return dp[i][buy][transc];
  if (buy) // buy is either 0 or 1. if its 1 then it means we'll buy. if 0 then notBuy. transc is done when there is both buy and sell.
  {
    return dp[i][buy][transc] = max(-vec[i] + buySell2(i + 1, 0, transc, n, vec, dp), 0 + buySell2(i + 1, 1, transc, n, vec, dp));
  }
  else
  {
    return dp[i][buy][transc] = max(vec[i] + buySell2(i + 1, 1, transc - 1, n, vec, dp), 0 + buySell2(i + 1, 0, transc, n, vec, dp));
  }
}

int buySell2funCall(vector<int> vec)
{
  int n = vec.size();
  vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
  return buySell2(0, 1, 2, n, vec, dp);
}

int buySell2Tabulation(vector<int> vec)
{
  int n = vec.size();
  vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, 0)));
  for (int i = n - 1; i >= 0; i--)
  {
    for (int buy = 0; buy < 2; buy++)
    {
      for (int transc = 1; transc < 3; transc++)
      {
        if (buy) // buy is either 0 or 1. if its 1 then it means we'll buy. if 0 then notBuy. transc is done when there is both buy and sell.
        {
          dp[i + 1][buy][transc] = max(-vec[i] + dp[i + 1][0][transc], 0 + dp[i + 1][1][transc]);
        }
        else
        {
          dp[i + 1][buy][transc] = max(vec[i] + dp[i + 1][1][transc - 1], 0 + dp[i + 1][0][transc]);
        }
      }
    }
  }
  return dp[0][1][2];
}

int buySell2SpaceOptimized(vector<int> vec)
{
  int n = vec.size();
  vector<vector<int>> ahead(2, vector<int>(3, 0));
  vector<vector<int>> cur(2, vector<int>(3, 0));
  for (int i = n - 1; i >= 0; i--)
  {
    for (int buy = 0; buy < 2; buy++)
    {
      for (int transc = 1; transc < 3; transc++)
      {
        if (buy) // buy is either 0 or 1. if its 1 then it means we'll buy. if 0 then notBuy. transc is done when there is both buy and sell.
        {
          cur[buy][transc] = max(-vec[i] + ahead[0][transc], 0 + ahead[1][transc]);
        }
        else
        {
          cur[buy][transc] = max(vec[i] + ahead[1][transc - 1], 0 + ahead[0][transc]);
        }
      }
    }
    ahead = cur;
  }
  return ahead[1][2];
}

int main() {

  int n =6;
  vector<int> vec = {7,1,5,3,6,4};
                                 
  cout<<"The maximum profit that can be generated is "<<buySell2funCall(vec);
  cout<<"The maximum profit that can be generated is "<<buySell2Tabulation(vec);
  cout<<"The maximum profit that can be generated is "<<buySell2SpaceOptimized(vec);
}
