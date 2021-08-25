#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n;
    cin>>k;

    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];

    sort(arr,arr+n);

    int small=arr[0]+k;
    int big=arr[n-1]-k;

    if(small>big)
        swap(small,big);

    for(int i=1;i<n-1;i++)
    {
        int sub=arr[i]-k;
        int add=arr[i]+k;

        if(sub>=small || add<=big)
                continue;

        else if(big-sub<=add-small)
                small=sub;

        else
                big=add;
    }
    cout<<min(big-small,arr[n-1]-arr[0]);

    return 0;
}
