#include <bits/stdc++.h>
#define ll long long
const ll N = 1e5+10;
const ll M = 1e7+7;
ll arr[N];
ll P[M];
using namespace std;
int main (){
    ll n, x, sum=0;
    cin>>n>>x;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    ll p = 0;
    p = abs(sum);
    //cout<<p<<endl;
    if (p==0)
    {
        cout<<0<<endl;
        return 0;
    }
    
    if (p<=x)
    {
        cout<<1<<endl;
    }
    else if(p>x)
    {
        cout<<(p/x)+(p%x!=0)<<endl;
    }
    
    
    
    
    
    
    return 0;
}
