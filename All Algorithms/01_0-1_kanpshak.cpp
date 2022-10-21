#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];

int knapSack(int W, int wt[], int val[], int n) 
{ 
    if(n == 0 || W <= 0){
        return 0;
    }
    if(dp[n][W] != -1) return dp[n][W];
    if(wt[n - 1] <= W){
        return dp[n][W] = max(val[n-1] + knapSack(W-wt[n-1], wt, val, n-1), knapSack(W, wt, val, n-1));
    }
    else{
        return dp[n][W] = knapSack(W, wt, val, n-1);
    }
}

int main(){
    int n, w;
    cin >> w >> n;
    int wt[n], val[n];
    for(int i = 0; i < n; i++){
        cin >> wt[i];
    }
    for(int i = 0; i < n; i++){
        cin >> val[i];
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= w; j++){
            dp[i][j] = -1;
        }
    }
    int profit = knapSack(w, wt, val, n);
    cout << profit;
    return 0;
}