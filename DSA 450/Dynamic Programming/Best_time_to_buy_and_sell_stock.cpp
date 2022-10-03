#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int maximumProfit(vector<int> &prices)
{
  int n = prices.size();
  int mini = prices[0];
  int profit = 0;
  for (int i = 1; i < n; i++)
  {
    int cost = prices[i] - mini;
    profit = max(profit, cost);
    mini = min(mini, prices[i]);
  }
  return profit;
}

int main() {

  vector<int> Arr  ={7,1,5,3,6,4};

  cout<<"The maximum profit by selling the stock is "<<maximumProfit(Arr);
}

// TC - O(N)
// SC - O(1)  
