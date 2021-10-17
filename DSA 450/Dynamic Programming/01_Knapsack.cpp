// Knapsack DP

#include <bits/stdc++.h>

using namespace std;

int t[101][101];

int knapsack(int wt[], int val[], int w, int n)
{
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < w+1; j++) {
            if (i == 0 || j == 0)
                t[i][j] = 0;
                
            if (wt[i-1] <= j)
                t[i][j] = max(val[i-1] + t[i-1][j - wt[i-1]], t[i-1][j]);
            
            else
                t[i][j] = t[i-1][j];
        }
    }
    
    return t[n][w];
}

int main()
{
    int n;
	cout << "n: ";
    cin >> n;
    
    int wt[n], val[n], w;
    
    cout << "weights: ";
    for (int i = 0; i < n; i++)
        cin >> wt[i];
        
    cout << "vals: ";
    for (int i = 0; i < n; i++)
        cin >> val[i];
        
    cout << "w: ";
    cin >> w;
    
    cout << knapsack(wt, val, w, n);
}
