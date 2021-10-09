#include <bits/stdc++.h>
using namespace std;

int sb(int arr[], int n, int x);

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		
		cout<<sb(a,n,x)<<endl;
	}
	return 0;
}




int sb(int arr[], int n, int x) 
{ 

    int curr_sum = 0, min_len = n+1; 
  
    int start = 0, end = 0; 
    while (end < n) 
    { 
        while (curr_sum <= x && end < n) 
            curr_sum += arr[end++]; 

        while (curr_sum > x && start < n) 
        { 
            if (end - start < min_len) 
                min_len = end - start; 
            curr_sum -= arr[start++]; 
        } 
    } 
    return min_len; 
} 
