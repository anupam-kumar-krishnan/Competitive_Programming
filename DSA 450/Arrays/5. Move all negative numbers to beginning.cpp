#include <bits/stdc++.h>
using namespace std;

void rearrange(int arr[], int n)
{
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0) {
			if (i != j)
				swap(arr[i], arr[j]);
			j++;
		}
	}
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}

int main()
{
   int n;
   cin>>n;

   int arr[n];
   for(int i=0;i<n;i++){
      cin>>ar[i];
   }
	 rearrange(arr, n);
	 printArray(arr, n);
	 return 0;
}
-----------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    
    int a[n],i;
    for(int i=0;i<n;i++)
        cin>>a[i];
        
    int j=0;
    
    for(i=0;i<n;i++)
    {
        if(a[i]<0)
        {
            swap(a[i],a[j]);
            j++;
        }
    }
    
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
}
