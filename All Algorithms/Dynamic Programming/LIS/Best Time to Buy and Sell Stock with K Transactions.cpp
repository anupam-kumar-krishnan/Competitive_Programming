#include <bits/stdc++.h>

using namespace std;


int maximumProfit(vector<int>& stocks, int n, int k)
{
    // dp of size [n+1][2][k+1] --> n represents no of days , 2 --> is for whether to buy or sell , k --> maximum of transactions allowed  
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
    for(int day = n-1; day>=0; day--)
    {
        for(int buy = 0; buy<=1; buy++)
        {
            for(int limit =1; limit<=k; limit++)
            {
                if(buy==0)//we can buy a stock
                {
                    dp[day][buy][limit] = max(dp[day+1][0][limit], -stocks[day] + dp[day+1][1][limit]);
                }
                if(buy==1)//we can sell the stock
                {
                    dp[day][buy][limit] = max(dp[day+1][1][limit], stocks[day] + dp[day+1][0][limit-1]);
                }
            }
        }
    }
    return dp[0][0][k];
}
int main() 
{
  vector<int> stock_prices = {3,2,6,5,0,3};
  int n = stock_prices.size();
  int k =2; 
  cout<<"The maximum profit that you can earn is "<<maximumProfit(stock_prices , n, k);
}