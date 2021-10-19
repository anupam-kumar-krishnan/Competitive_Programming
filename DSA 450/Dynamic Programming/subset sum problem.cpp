// Subset sum problem

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
	cout << "n: ";
    cin >> n;
    
    int arr[n], sum;
    
    cout << "arr: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
        
    cout << "sum: ";
    cin >> sum;
    
    bool t[n+1][sum+1];
    
	//Initialization
    for (int i = 0; i < n+1; i++)
        t[i][0] = true;

    for (int i = 1; i < sum+1; i++)
        t[0][i] = false;
    
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < sum+1; j++)
        {
            if (arr[i-1] <= j)
				// use + instead of || for finding the number of subsets with given sum and change datatype of t to int
				t[i][j] = t[i-1][j - arr[i-1]] || t[i-1][j];
                
            else
                t[i][j] = t[i-1][j];
        }
    }
    
    cout << t[n][sum];
}
