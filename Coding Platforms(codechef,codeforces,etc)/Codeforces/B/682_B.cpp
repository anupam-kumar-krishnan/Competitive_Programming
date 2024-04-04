#include <bits/stdc++.h>
#define ll long long
const ll N = 1e5+10;
const ll M = 1e7+7;
ll arr[N];
ll P[M];
using namespace std;
int main (){
    ll n;
    cin>>n;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
       cin>>a[i];
    }
    sort(a, a+n);
    ll count=1;
    for (int i = 0; i < n; i++)
    {
        if (a[i]>=count)
        {
            count++;
        }
        
    }
    cout<<count<<endl;
    
    
    return 0;
}
