#include<iostream>
using namespace std;

int TrapWater(int arr[] , int n )
{
    int res = 0;
    int lmax[n] , rmax[n];
    lmax[0] = arr[0];
    for(int i = 1 ; i<n-1 ; i++)
    {
        lmax[i] = max(arr[i],lmax[i-1]);
    }
    rmax[0] = arr[n-1];
    for(int i = n-2 ; i>=0 ; i--)
    {
        rmax[i] = max(arr[i],rmax[i+1]);
    }
    for(int i = 1 ; i<n-1 ; i++)
    {
        res += max(lmax[i],rmax[i]) - arr[i];
    }
    return res;
}

int main()
{
    int n = 5;
    int arr[n] = {3,0,1,2,5};
    cout<<TrapWater(arr , n);
}
