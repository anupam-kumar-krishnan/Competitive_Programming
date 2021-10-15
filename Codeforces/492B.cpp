// codforces solution 

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int n,l;
    cin>>n>>l;
    int a[n];
    for(int i=0; i<n ; i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    float diff = 0;
    float value = 0;
    for(int i=0; i<n; i++)
    {
       value = a[i]-a[i-1];
       if(value>diff)
       {
           diff = float(value);
       }
    }
    diff = diff/2;
    int s,e;
    s = a[0];
    e = l-a[n-1];
    if(float(s)>diff)
        diff = float(s);
    if(float(e)>diff)
        diff = float(e);
    cout<<fixed<<setprecision(10)<<diff<<endl;
}