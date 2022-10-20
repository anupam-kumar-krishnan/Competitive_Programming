#include<iostream>
using namespace std;
int main()
{
    int n,k,count_m=0,count=0;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if (a[i]==0)
        {
            count_m=count_m+1;
        }
    }
    int max=a[k-1];
    for(int i=0;i<n;i++)
    {
        if ((a[i]>=max)&&(a[i]!=0))
        {
            count=count+1;
        }
    }
    if(count_m==n)
    {
        cout<<0<<endl;
    }
    else
    {
        cout<<count<<endl;
    }
    return 0;
}
